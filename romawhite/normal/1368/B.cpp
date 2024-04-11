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

Int f(VI A) {
    Int r = 1;
    FOR(i,0,SZ(A))
        r *= A[i];
    return r;
}

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    Int n;
    cin >> n;
    string S = "codeforces";
    VI A(SZ(S), 1);

    FOR(it,0,1000) {
        if (f(A) >= n)
            break;
        A[it % SZ(A)] ++;
    }

    FOR(i,0,SZ(A))
        FOR(j,0,A[i])
            cout << S[i];
    cout << endl;
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}