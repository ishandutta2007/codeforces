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
const int MAX = 1007;
const int MOD = 998244353;


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);

    int n, k;
    cin >> n >> k;

    Int s = 0;
    Int res = 1;
    int prev = -1;
    FOR(i,0,n) {
        int x;
        cin >> x;
        if (x >= n - k + 1) {
            s += x;
            if (prev != -1) {
                res *= (i - prev);
                res %= MOD;
            }
            prev = i;
        }
    }

    cout << s << ' ' << res << endl;
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}