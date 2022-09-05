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
const int MAX = 200007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);

Int F[MAX];
Int IF[MAX];

Int bpow(Int a, Int k)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        k /= 2;
    }
    return res;
}

Int C(int n, int k)
{
    return F[n] * IF[k] % MOD * IF[n - k] % MOD;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    F[0] = 1;
    FOR(i,1,MAX)
    {
        F[i] = F[i - 1] * i % MOD;
    }
    FOR(i,0,MAX)
    {
        IF[i] = bpow(F[i] , MOD - 2);
    }


    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    VI A(n);
    FOR(i,0,n)
        cin >> A[i];

    int a = 0;
    int b = 0;
    FOR(i,0,n)
    {
        if (A[i] == A[(i + 1) % n])
        {
            ++ a;
        }
        else
        {
            ++ b;
        }
    }


    Int res = 0;

    FOR(i, 0, b)
    {
        Int cur = bpow(k - 2, i) * C(b, i) % MOD;
        int t = b - i;
        Int c = bpow(2, t);
        if (t % 2 == 0)
        {
            c -= C(t, t / 2);
            if (c < 0)
                c += MOD;
        }
        c *= bpow(2, MOD - 2);
        c %= MOD;
        res += cur * c % MOD;
        res %= MOD;
    }

    res *= bpow(k, a);
    res %= MOD;

    cout << res << endl;


}