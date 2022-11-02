#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n, m;
int t;
bool gr[MN][MN];
int tim[MN][MN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pii> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    FOR(i, 1, n){
        FOR(j, 1, m){
            char c;
            cin >> c;
            if(c == '1') gr[i][j] = true;
        }
    }
    memset(tim, -1, sizeof tim);
    FOR(i, 1, n){
        FOR(j, 1, m){
            F0R(d, 4){
                int nx = i+dx[d], ny = j+dy[d];
                if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                if(gr[i][j] == gr[nx][ny]){
                    tim[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
    }
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        int x = top.f, y = top.s;
        F0R(d, 4){
            int nx = x+dx[d], ny = y+dy[d];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(tim[nx][ny] == -1){
                tim[nx][ny] = tim[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    F0R(_, t){
        int i, j; ll p;
        cin >> i >> j >> p;
        //cout << tim[i][j] << " ";
        if(tim[i][j] == -1 || tim[i][j] > p) cout << gr[i][j] << "\n";
        else cout << (p-tim[i][j]+gr[i][j])%2 << "\n";
    }
    
    return 0;
}