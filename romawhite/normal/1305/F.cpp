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
const int MAX = 1007;

int n;
vector<Int> A;

Int res;

void update(Int p) {
    Int cur = 0;
    FOR(i,0,n) {
        Int m = A[i] % p;
        if (m == A[i])
            cur += (p - m);
        else
            cur += min(m, p - m);
        if (cur > res)
            break;
    }
    res = min(res, cur);
}

void f(Int x) {
    for(Int i = 2; i * i <= x; ++ i) {
        if (x % i == 0) {
            update(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1)
        update(x);
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    cin >> n;
    // n = 200000;
    A.resize(n);
    FOR(i,0,n)
        cin >> A[i];

    res = 0;
    FOR(i,0,n)
        res += A[i] % 2;

    int it = 0;
    while(true) {
        if (1.0 * clock() / CLOCKS_PER_SEC > 2.0)
            break;
        ++ it;
        int i = rng() % n;
        f(A[i]);
        f(A[i] + 1);
        if (A[i] > 1)
            f(A[i] - 1);
    }

    cout << res << endl;

    cerr << it << endl;
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}