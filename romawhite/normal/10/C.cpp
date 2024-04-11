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
const int MAX = 150007;
const int MOD = 998244353;

int A[9];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    // mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin >> n;

    int cnt = 0;

    FOR(i,1,n + 1)
    {
        cnt += n / i;
    }

    FOR(i,1,n + 1) {
        A[i % 9] ++;
    }

    Int res = 0;
    FOR(i,0,9)
        FOR(j,0,9)
            FOR(k,0,9) {
                if (k == (i * j) % 9)
                    res += 1LL * A[i] * A[j] * A[k];
            }
    res -= cnt;

    cout << res << endl;




	return 0;
}