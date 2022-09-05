

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define MANY 18000000000000000000ull

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 64;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 20;

int gcd(int a , int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

map<int,int> M;

int main()
{

   //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    FOR(t,0,n)
    {
        vector<int> p;
        int x;
        cin >> x;
        int y = 1;
        for(int i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                p.push_back(i);
                y *= i;
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x != 1)
        {
            p.push_back(x);
            y *= x;
        }
        a.push_back(y);
        FOR(mask , 0 , 1 << p.size())
        {
            int z = 1;
            FOR(i,0,p.size())
            {
                if (mask & (1 << i))
                {
                    z *= p[i];
                }
            }
            b.push_back(z);
        }
    }
    b.push_back(0);
    sort(ALL(b));
    b.resize(unique(ALL(b)) - b.begin());
    FOR(i,0,b.size())
    {
        M[b[i]] = i;
    }

    vector<int> dp(b.size(), INF);
    dp[0] = 0;

    vector<int> c(n);
    FOR(i,0,n)
    {
        cin >> c[i];

    }


    FOR(i,0,a.size())
    {
        FOR(j,0,b.size())
        {
            if (dp[j] < INF)
            {
                int g = gcd(b[j] , a[i]);
                int id = M[g];
                dp[id] = min(dp[id] , dp[j] + c[i]);
            }
        }
    }
    if (dp[1] == INF)
    {
        dp[1] = -1;
    }
    cout << dp[1] << endl;

    return 0;
}