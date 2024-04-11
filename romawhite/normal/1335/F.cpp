#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1000007;
const int MOD = 998244353;

int G[MAX];
VI RG[MAX];
int B[MAX];
bool U[MAX];
int UU[MAX];
int H[MAX];

void dfs(int v, int id, int cycle) {
    if (B[v])
        H[id] = 1;
    U[v] = true;
    // cout << "dfs " << v << endl;
    for(int to: RG[v]) {
        if (U[to])
            continue;
        dfs(to, (id - 1 + cycle) % cycle, cycle);
    }
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    // mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    FOR(tt,0,t) {
        int n, m;
        cin >> n >> m;
        vector<string> C(n);
        vector<string> S(n);

        FOR(i,0,n)
            cin >> C[i];
        FOR(i,0,n)
            cin >> S[i];

        int N = n * m;
        FOR(i,0,n)
            FOR(j,0,m)
                B[i * m + j] = 1 - (C[i][j] - '0');
        
        FOR(i,0,N) {
            U[i] = false;
            UU[i] = 0;
            RG[i].clear();
        }
        
        FOR(i,0,n)
            FOR(j,0,m) {
                int xx = i;
                int yy = j;
                if (S[i][j] == 'D')
                    ++xx;
                if (S[i][j] == 'U')
                    --xx;
                if (S[i][j] == 'R')
                    ++yy;
                if (S[i][j] == 'L')
                    --yy;
                int a = i * m + j;
                int b = xx * m + yy;
                G[a] = b;
                RG[b].push_back(a);
            }

        int res = 0;
        int rb = 0;

        FOR(i,0,N) {
            if (U[i])
                continue;
            int v = i;
            VI CC;
            VI C;
            while (true) {
                CC.push_back(v);
                UU[v] = SZ(CC);
                v = G[v];
                if (UU[v]) {
                    FOR(t,UU[v] - 1, SZ(CC))
                        C.push_back(CC[t]);
                    break;
                }
            }

            // cout << "START CYCLE " << i << endl;
            // FOR(i,0,SZ(C))
            // {
            //     cout << C[i] << ' ';
            // }
            // cout << endl;
            // cout << "END CYCLE" << endl;

            res += SZ(C);
            FOR(i,0,SZ(C))
                H[i] = 0;
            FOR(i,0,SZ(C))
                U[C[i]] = 1;
            FOR(i,0,SZ(C))
                dfs(C[i], i, SZ(C));
            // cout << "END DFS" << endl;
            FOR(i,0,SZ(C))
                rb += H[i];
        }
        cout << res << ' ' << rb << endl;

    }


	return 0;
}