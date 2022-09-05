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
const int MAX = 150007;
const int MOD = 998244353;

int A[9];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    // mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n, m;
    cin >> n >> m;
    VI A;
    VI B;
    Int sa = 0, sb = 0;
    FOR(i,0,n) {
        int x;
        cin >> x;
        A.push_back(x);
        sa += x;
    }
    FOR(i,0,m) {
        int x;
        cin >> x;
        B.push_back(x);
        sb += x;
    }

    UInt res = (UInt)11 * INF * INF;

    sort(ALL(A));
    sort(ALL(B));


    UInt c = sa;
    FOR(i,1,SZ(A) + 1) {
        c -= A[SZ(A) - i];
        res = min(res, c + sb * i);
    }
    c = sb;
    FOR(i,1,SZ(B) + 1) {
        c -= B[SZ(B) - i];
        res = min(res, c + sa * i);
    }

    cout << res << endl;

	return 0;
}