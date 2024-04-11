#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 100000;
const int MOD = 1000000007;
const double Pi = acos(-1.);

VI A[MAX];

int main()
{
    
    int n;
    cin >> n;

    FOR(i,0,n)
    {   
        int x;
        cin >> x;
        x = n - x;
        A[x].push_back(i);
    }

    bool ok = 1;
    FOR(i,1,n + 1)
    {   
        if (SZ(A[i]) % i != 0)
        {   
            ok = 0;
        }
    }
    if (!ok)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;

    int c = 0;
    VI res(n);

    FOR(i,1,n + 1)
    {   
        FOR(j,0,SZ(A[i]))
        {   
            if (j % i == 0)
                ++ c;
            res[A[i][j]] = c;
        }
    }
    FOR(i,0,n)
    {
        cout << res[i] << ' ';
    }
    cout << endl;




    return 0;
}