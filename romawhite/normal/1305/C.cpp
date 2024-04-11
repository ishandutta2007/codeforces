#include "bits/stdc++.h"
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
const int MAX = 100007;

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << 0 << endl;
        return 0;
    }

    VI A(n);
    FOR(i,0,n) {
        cin >> A[i];
    }
    
    int res = 1;
    FOR(i,0,n)
        FOR(j,i + 1, n)
        {
            res *= abs(A[i] - A[j]) % m;
            res %= m;
        }

    cout << res << endl;

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}