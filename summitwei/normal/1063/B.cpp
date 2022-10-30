#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 2005
int n, m;
int r, c;
int x, y;
char gr[MN][MN];
int dy[4] = {0, 1, 0, -1}; //4th is left
int dx[4] = {1, 0, -1, 0};
int mn[MN][MN]; //mn amt of lefts
bool vis[MN][MN];

deque<pii> ree;
int bfs(){
    memset(mn, 0x3f, sizeof mn);
    mn[r][c] = 0;
    ree.push_front({r, c});
    //int cnt = 1;
    while(!ree.empty()){
        int cx = ree.front().f, cy = ree.front().s;
        ree.pop_front();
        if(vis[cx][cy]) continue;
        vis[cx][cy] = true;
        int v = mn[cx][cy];
        //cout << "mn dist to " << cx << " " << cy << " " << v << "\n";
        F0R(i, 4){
            int nx = cx+dx[i], ny = cy+dy[i];
            //cout << "hmm\n";
            //cout << "cur " << mn[nx][ny] << "\n";
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            //cout << "double hmm " << gr[nx][nx] << "\n";
            if(gr[nx][ny] == '*') continue;
            //cout << "checking " << nx << " " << ny << "\n";
            if(i == 1){
                //int rt = cy-c+v;
                //if(rt == y) continue;
                mn[nx][ny] = min(mn[nx][ny], mn[cx][cy]);
                //++cnt;
                ree.push_front({nx, ny});
                //cout << "hi i found " << nx << " " << ny << "\n";
            } else if(i == 3){
                //if(v == x) continue;
                mn[nx][ny] = min(mn[nx][ny], mn[cx][cy]+1);
                //++cnt;
                ree.push_back({nx, ny});
            } else{
                mn[nx][ny] = min(mn[nx][ny], mn[cx][cy]);
                //++cnt;
                ree.push_front({nx, ny});
            }
        }
    }
    //return cnt;
}
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    cin >> n >> m >> r >> c >> x >> y;
    --r; --c;
    F0R(i, n){
        F0R(j, m){
            cin >> gr[i][j];
        }
    }
    //cout << bfs() << "\n";

    bfs();
    int sm = 0;
    F0R(i, n){
        F0R(j, m){
            int sl = mn[i][j];
            int sr = j-c+sl;

            //cout << mn[i][j] << " ";

            if(sl <= x && sr <= y) ++sm;
        }
        //cout << "\n";
    }

    cout << sm << "\n";

    return 0;
}