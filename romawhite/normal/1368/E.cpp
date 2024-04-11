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
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
const int MOD = 1000000007;

mt19937 rng;

VI G[MAX];
VI GR[MAX];
int indeg[MAX];
int outdeg[MAX];

set<PII> S;

bool U[MAX];
bool B[MAX];

void del(int v) {
    for(int to: G[v]) {
        if (U[to]) continue;
        S.erase(MP(indeg[to] * outdeg[to], to));
        indeg[to] --;
        S.insert(MP(indeg[to] * outdeg[to], to));
    }
    for(int to: GR[v]) {
        if (U[to]) continue;
        S.erase(MP(indeg[to] * outdeg[to], to));
        outdeg[to] --;
        S.insert(MP(indeg[to] * outdeg[to], to));
    }
}

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    // t = 1;
    FOR(tt, 0, t) {
        int n, m;
        cin >> n >> m;
        // n = 200000;
        // m = 2 * n - 2;
        FOR(i, 0, n) {
            G[i].clear();
            U[i] = 0;
            indeg[i] = 0;
        }
        FOR(i,0,m) {
            int a, b;
            cin >> a >> b;
            // a = i / 2 + 1;
            // b = min(a + 1 + i % 2, n);
            --a; --b;
            G[a].push_back(b);
            indeg[b] ++;
        }

        set<int> res;

        FOR(i,0,n)
            sort(ALL(G[i]));

        FOR(i,0,n) {
            if (!U[i] && indeg[i] > 0) {
                for(int to: G[i]) {
                    if (U[to])
                        continue;
                    U[to] = true;
                    res.insert(to);
                    for(int to2: G[to]) {
                        if (!U[to2]) {
                            indeg[to2] --;
                        }
                    }
                }
            }
        }

        cout << SZ(res) << endl;
        for(int v: res) {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}