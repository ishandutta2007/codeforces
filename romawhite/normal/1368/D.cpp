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
const int MAX = 277;
const int MOD = 1000000007;

mt19937 rng;


int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin >> n;
    VI A(n);
    FOR(i,0,n) {   
        cin >> A[i];
    }
    VI B(n);
    FOR(j,0,30) {
        int cnt = 0;
        FOR(i,0,n) {
            if (A[i] & (1 << j))
                ++ cnt;
        }
        FOR(i,0,cnt) {
            B[i] += (1 << j);
        }
    }

    Int res = 0;
    FOR(i,0,n)
        res += 1LL * B[i] * B[i];

    cout << res << endl;
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}