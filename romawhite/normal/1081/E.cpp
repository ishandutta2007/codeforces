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
const int MAX = 200007;
const int MOD = 998244353;
const double Pi = acos(-1.);

VI d[MAX];

int main()
{
    int n;
    cin >> n;

    FOR(i,1,MAX)
    {
        for(int j = i; j < MAX; j += i)
        {
            d[j].push_back(i);
        }
    }

    vector<Int> res;

    Int last = 0;

    FOR(i,0,n / 2)
    {   
        int x;
        cin >> x;

        Int val = -1;
        Int A , B = 1LL * INF * INF;

        FOR(j,0,SZ(d[x]))
        {   
            int d1 = d[x][j];
            int d2 = x / d1;
            if (d1 % 2 != d2 % 2) continue;
            if (d1 >= d2) continue;
            Int b = (d1 + d2) / 2;
            Int a = (d2 - d1) / 2;
            if (a * a <= last) continue;
            if (b < B)
            {   
                val = a * a - last;
                A = a;
                B = b;
            }
        }

        if (val == -1)
        {
            cout << "No" << endl;
            return 0;
        }

        res.push_back(val);
        res.push_back(x);
        last = B * B;


    }

    cout << "Yes" << endl;
    FOR(i,0,n)
    {
        cout << res[i] << ' ';
    }
    cout << endl;


    return 0;
}