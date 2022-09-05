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
 
const int MOD = 1000000007;
 
const double Pi = acos(-1.0);

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;
    VI A(n);
    FOR(i,0,n)
    {
        cin >> A[i];
    }

    vector<Int> S;
    S.push_back(0);
    FOR(i,0,n)
    {
        S.push_back(S[i] + A[i]);
    }
    
    vector<Int> p;
    Int sum = S[n];
    if (sum == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    for(Int i = 2; i * i <= sum; ++i)
        if (sum % i == 0)
        {
            p.push_back(i);
            while (sum % i == 0)
                sum /= i;
        }
    if (sum != 1)
        p.push_back(sum);
    
    Int res = 1LL * INF * INF;
    for(Int d: p) {
        Int cur = 0;
        FOR(i,1,n) {
            cur += min(S[i] % d, d - S[i] % d);
        }
        res = min(res, cur);
    }

    cout << res << endl;

}