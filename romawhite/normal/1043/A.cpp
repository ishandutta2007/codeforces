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
    VI A(n);
    FOR(i,0,n)
    cin >> A[i];
    
    for(int k = 1; k <= 201; ++k)
    {
        bool ok = true;
        int s1 = 0;
        int s2 = 0;
        FOR(i,0,n)
        {
            if (A[i] > k)
            {
                ok = false;
                break;
            }
            s1 += A[i];
            s2 += k - A[i];
        }
        
        if (s2 > s1 && ok)
        {
            cout << k << endl;
            return 0;
        }
    }
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}