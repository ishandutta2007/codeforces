#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL * INF*INF;
const int MAX = 10007;
const double PI = acos(-1.);
const double EPS = 1e-8;

int sign(int x)
{
    return x > 0;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        Int a , b;
        cin >> a >> b;
        if (b < a - 1)
        {
            cout << "NO" << endl;
            continue;
        }
        
        Int c = 2 * a - 1;
        bool ok = 1;
        
        for(Int i = 2; i * i <= c; ++i)
            if (c % i == 0)
            {
                ok = 0;
                break;
            }
        
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        
    }
    
    return 0;
}