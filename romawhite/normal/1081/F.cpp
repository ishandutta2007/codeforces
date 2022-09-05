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

int get(int L, int R)
{   
    cout << "? " << L + 1 << ' ' << R + 1 << endl;
    int v;
    cin >> v;
    if (v == -1)
        throw -1;
        return v;
}


int main()
{
    int n , t;
    cin >> n >> t;

    if (n == 1)
    {
        if (t == 1)
        {   
            cout << "! 1" << endl;
        }
        else
        {   
            cout << "! 0" << endl;
        }
        return 0;
    }

    if (n % 2 == 0)
    {   
        string res = "";
        int prev = 0;

        FOR(i,0,n)
        {
            bool L = false;
            bool R = false;

            int v;
            int last = t;

            while (!L || R)
            {   
                v = get(i, i);

                if (abs(v - last) % 2 == (i + 1) % 2)
                {   
                    L ^= 1;
                }
                else
                {   
                    R ^= 1;
                }
                last = v;
            }

            if (t - prev + (i - prev) - 1 == v)
            {   
                res += '1';
                prev ++;
            }
            else
            {   
                res += '0';
            }

            while (L || R)
            {   
                v = get(i, i);

                if (abs(v - last) % 2 == (i + 1) % 2)
                {   
                    L ^= 1;
                }
                else
                {   
                    R ^= 1;
                }
                last = v;
            }

        }

        cout << "! " << res << endl;
        return 0;
    }

    string res0 = "0";
    string res1 = "1";
    int prev0 = 0;
    int prev1 = 1;

    bool c0 = true;
    bool c1 = true;

    FOR(i,1,n)
    {
        bool L = false;
        bool R = false;

        int v;
        int last = t;

        while (!L || R)
        {   
            v = get(i - 1, i);

            if (abs(v - last) % 2 == (i + 1) % 2)
            {   
                L ^= 1;
            }
            else
            {   
                R ^= 1;
            }
            last = v;
        }

        if (t - prev0 + (i - prev0) - 1 == v)
        {   
            res0 += '1';
            prev0 ++;
        }
        else
        {   
            if (t - prev0 + (i - prev0) + 1 != v) c0 = false;
            res0 += '0';
        }

        if (t - prev1 + (i - prev1) - 1 == v)
        {   
            res1 += '1';
            prev1 ++;
        }
        else
        {   
            if (t - prev1 + (i - prev1) + 1 != v) c1 = false;
            res1 += '0';
        }

        while (L || R)
        {   
            v = get(i - 1, i);

            if (abs(v - last) % 2 == (i + 1) % 2)
            {   
                L ^= 1;
            }
            else
            {   
                R ^= 1;
            }
            last = v;
        }

    }

    int cnt0 = 0;
    int cnt1 = 0;

    FOR(i,0,n)
    {
        cnt0 += res0[i] - '0';
        cnt1 += res1[i] - '0'; 
    }

    if (cnt0 != t) c0 = false;
    if (cnt1 != t) c1 = false;

    int mx0 = max(t + 1 , n - t);
    int mx1 = max(t , n - t + 1);

    // cerr << res0 << ' ' << res1 << ' ' << c0 << ' ' << c1 << endl;

    int mx = -1;
    FOR(it,0,100)
    {   
        mx = max(mx , get(0,0));
    }

    if (mx == mx0) c1 = false;
    else
        c0 = false;


    if (!c0)
        cout << "! " << res1 << endl;
    else
        cout << "! " << res0 << endl;




    return 0;
}