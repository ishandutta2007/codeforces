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
const int MAX = 14;
const int MOD = 998244353;

int A[MAX][MAX];

vector<Int> dp[1 << MAX][MAX];

int POPCNT[1 << MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);

    POPCNT[0] = 0;
    FOR(i,1,1 << MAX)
        POPCNT[i] = POPCNT[i / 2] + i % 2;

    int n;
    cin >> n;
    // n = 14;
    FOR(i,0,n) {
        string s;
        cin >> s;
        FOR(j,0,n) {
            A[i][j] = s[j] - '0';
            // A[i][j] = rng() % 2;
            // A[j][i] = A[i][j];
        }
    }   
    
    FOR(i,1,1 << n) {
        int c = POPCNT[i] - 1;
        FOR(j,0,n) {
            dp[i][j].resize(1 << c, 0);
        }
    }

    FOR(i, 0, n) {
        dp[1 << i][i][0] = 1;
    }

    FOR(mask, 1, 1 << n) {
        int c = POPCNT[mask];
        FOR(j,0,n) {
            if (!(mask & (1 << j)))
                continue;
            FOR(m, 0, 1 << (c - 1)) {
                Int val = dp[mask][j][m];
                if (val == 0) continue;
                FOR(nx, 0, n) {
                    if (mask & (1 << nx))
                        continue;
                    dp[mask | (1 << nx)][nx][m + A[j][nx] * (1 << (c - 1))] += val;
                }
            }
        }
    }

    FOR(i,0,1 << (n - 1)){
        Int res = 0;
        FOR(j,0,n) {
            res += dp[(1 << n) - 1][j][i];
        }
        cout << res << ' ';
    }

    
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}