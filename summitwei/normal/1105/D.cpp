#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
#define MP 10
int n, m, p;
int sp[MP];
int g[MN][MN];
pii d[MN][MN][MP]; //amt of turns, dist
pii st[MN];

queue<pii> q[10];

/*void bfs(int cp, int x, int y){
    queue<pii> q;
    d[x][y][cp] = 0;
    q.pb(mp(x, y));
    
    while(!q.empty()){
        pii top = q.top();
        q.pop();
        
        if(x != 0 && g[x-1][y] != -1 && d[x-1][y][cp] == -1){
            d[x-1][y][cp] = d[x][y][cp] + 1;
            q.pb(mp(x-1, y));
        }
        if(y != 0 && g[x][y-1] != -1 && d[x][y-1][cp] == -1){
            d[x][y-1][cp] = d[x][y][cp] + 1;
            q.pb(mp(x, y-1));
        }
        if(x != n && g[x+1][y] != -1 && d[x+1][y][cp] == -1){
            d[x+1][y][cp] = d[x][y][cp] + 1;
            q.pb(mp(x+1, y));
        }
        if(y != m && g[x][y+1] != -1 && d[x][y+1][cp] == -1){
            d[x][y+1][cp] = d[x][y][cp] + 1;
            q.pb(mp(x, y+1));
        }
    }
}*/

int amt[MP];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //memset(d, -1, sizeof(d[0][0][0])*MN*MN*MP);

    cin >> n >> m >> p;
    FOR(i, 1, p){
        cin >> sp[i];
    }
    F0R(i, n){
        F0R(j, m){
            char c;
            cin >> c;
            if(c == '#') g[i][j] = -1;
            else if(c == '.') g[i][j] = 0;
            else{
                g[i][j] = c-'0';
                d[i][j][c-'0'] = mp(1, 0); //question mark on .s
                q[c-'0'].push(mp(i, j));
                //cout << c-'0' << " " << i << " " << j << "\n";
            }
        }
    }

    bool af = true;
    int t = 1;
    while(af){
        af = false;

        FOR(i, 1, p){
            while(!q[i].empty() && d[q[i].front().f][q[i].front().s][i].f == t){
                pii top = q[i].front();
                q[i].pop();

                int x = top.f;
                int y = top.s;
                int tm = d[x][y][i].s;
                //g[x][y] = i;
                //cout << "proc " << x << " " << y << " " << i << "\n";

                if(x != 0 && g[x-1][y] == 0 && d[x-1][y][i] == mp(0, 0)){
                    d[x-1][y][i] = (tm+1 == sp[i]) ? mp(t+1, 0) : mp(t, tm+1);
                    g[x-1][y] = i;
                    q[i].push(mp(x-1, y));
                }
                if(y != 0 && g[x][y-1] == 0 && d[x][y-1][i] == mp(0, 0)){
                    d[x][y-1][i] = (tm+1 == sp[i]) ? mp(t+1, 0) : mp(t, tm+1);
                    g[x][y-1] = i;
                    q[i].push(mp(x, y-1));
                }
                if(x != n-1 && g[x+1][y] == 0 && d[x+1][y][i] == mp(0, 0)){
                    d[x+1][y][i] = (tm+1 == sp[i]) ? mp(t+1, 0) : mp(t, tm+1);
                    g[x+1][y] = i;
                    q[i].push(mp(x+1, y));
                }
                if(y != m-1 && g[x][y+1] == 0 && d[x][y+1][i] == mp(0, 0)){
                    d[x][y+1][i] = (tm+1 == sp[i]) ? mp(t+1, 0) : mp(t, tm+1);
                    g[x][y+1] = i;
                    q[i].push(mp(x, y+1));
                }
            }

            if(!q[i].empty()) af = true;
        }

        t++;
    }

    F0R(i, n){
        F0R(j, m){
            if(g[i][j] > 0){
                amt[g[i][j]]++;
            }
        }
    }

    FOR(i, 1, p){
        cout << amt[i] << " ";
    }

    return 0;
}