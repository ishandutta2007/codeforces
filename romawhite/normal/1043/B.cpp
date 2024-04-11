#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL*INF*INF;
const int MAX = 307;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 1000000007;



int main()
{
//        freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    VI A(n + 1);
    FOR(i,1,n + 1)
    {
        cin >> A[i];
    }
    
    VI B;
    FOR(i,0,n)
    {
        B.push_back(A[i  +1] - A[i]);
    }
    VI res;
    
    FOR(k,1,n + 1)
    {
        bool ok = true;
        
        FOR(i,0,n)
        {
            if (B[i] != B[i % k])
            {
                ok = false;
            }
        }
        if (ok)
        {
            res.push_back(k);
        }
        
    }
    cout << SZ(res) << endl;
    FOR(i,0,SZ(res))
    cout << res[i] << ' ';
    cout << endl;
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}