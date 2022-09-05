#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 1000007;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

Int sy[4][MAX];

Int bpow(Int a, int k)
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

Int Sqrt(Int x)
{
    Int y = sqrt(1.0 * x);
    -- y;
    if (y < 0) ++ y;
    while ((y + 1) * (y + 1) <= x) ++ y;
    return y;
}

int main()
{
    FOR(i,1,MAX)
    {
        FOR(j,0,4)
        {
            sy[j][i] = (sy[j][i - 1] + bpow(i , 2 * j)) % MOD;
        }
    }
    
    Int m;
    cin >> m;
    
    Int res = 0;
    
    Int inv6 = bpow(6 , MOD - 2);
    
    for(Int x = 0; x * x <= m; ++x)
    {
        
        Int a = (m - x * x + 1) % MOD;
        Int b = (m + 2 * x * x) % MOD;
        
        Int R = Sqrt(m - x * x);
        
        Int add = a * (a + 1) % MOD * b % MOD;
        add += 2 * a * (a + 1) % MOD * b % MOD * sy[0][R] % MOD;

        
        add += 2 * ( 2 * a * (a + 1) % MOD + (MOD - (2 * a + 1) * b % MOD) % MOD) % MOD * sy[1][R] % MOD;
        

        
        add += 2 * (b + (MOD - (4 * a + 2) % MOD) % MOD) * sy[2][R] % MOD;

        
        add += 2 * 2 * sy[3][R] % MOD;

        
        if (x != 0) add *= 2;
        res += add;
        res %= MOD;
        
    }
    res = res * inv6 % MOD;
    
    /*Int res2 = 0;
    FOR(x,-m,m + 1)
        FOR(y,-m,m + 1)
    {
            if (x * x + y * y <= m)
            {
                Int a = m - x * x - y * y;
                if (y == 0)
                    res2 += (a + 1) * (a + 2) * (m + 2 * x * x + 2 * y * y);
            }
    }
    
    cout << res2 << endl;*/
    
    cout << res << endl;
    

    
    
    return 0;
}