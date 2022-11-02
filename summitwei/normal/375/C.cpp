#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 25
#define MT 10
int n, m;
char gr[MN][MN];
int t;
int tr[MT];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dis[MN][MN][1<<MT];
queue<pair<pii, int> > ree;
pii st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> gr[i][j];
            if(gr[i][j] >= '1' && gr[i][j] <= '8'){
                ++t;
            }
            if(gr[i][j] == 'S') st = {i, j};
        }
    }
    F0R(i, t){
        cin >> tr[i];
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(gr[i][j] == 'B'){
                gr[i][j] = '1'+t;
                tr[t] = -INF/10;
                ++t;
            }
        }
    }
    
    memset(dis, -1, sizeof dis);
    dis[st.f][st.s][0] = 0;
    ree.push({st, 0});
    while(!ree.empty()){
        pair<pii, int> top = ree.front();
        ree.pop();
        
        //cout << "proc " << top.f.f << " " << top.f.s << " " << top.s << " " << dis[top.f.f][top.f.s][top.s] << "\n";
        
        F0R(dir, 4){
            int nx = top.f.f+dx[dir];
            int ny = top.f.s+dy[dir];
            if(nx == 0 || ny == 0 || nx > n || ny > m) continue;
            if(gr[nx][ny] != '.' && gr[nx][ny] != 'S') continue;
            
            //cout << "doing " << nx << " " << ny << "\n";
            
            int ns = top.s;
            if(nx != top.f.f){
                int mx = max(top.f.f, nx);
                FOR(i, 1, ny){
                    if(gr[mx][i] >= '1' && gr[mx][i] <= '8'){
                        int d = gr[mx][i]-'1';
                        ns ^= (1<<d);
                    }
                }
            }
            if(dis[nx][ny][ns] != -1) continue;
            dis[nx][ny][ns] = dis[top.f.f][top.f.s][top.s]+1;
            ree.push({{nx, ny}, ns});
        }
    }
    
    int mx = 0;
    F0R(i, 1<<t){
        int sm = 0;
        F0R(j, t) if(i&(1<<j)) sm += tr[j];
        if(dis[st.f][st.s][i] == -1) continue;
        mx = max(mx, sm-dis[st.f][st.s][i]);
        //cout << i << " " << sm << " " << sm-dis[st.f][st.s][i] << "\n";
    }
    
    cout << mx << "\n";

    return 0;
}