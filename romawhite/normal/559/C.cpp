#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

Int fact[MAX];
Int fact1[MAX];

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

Int C(int n, int k)
{
    return fact[n] * fact1[k] % MOD * fact1[n - k] % MOD;
}

Int dp[2007];

int main()
{
    //freopen("in.txt" , "r", stdin);
    fact[0] = 1;
    FOR(i,1,MAX)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    FOR(i,0,MAX)
    {
        fact1[i] = bpow(fact[i] , MOD - 2);
    }
    
    int h , w, n;
    cin >> h >> w >> n;
    vector<pair<int,int> > a;
    FOR(i,0,n)
    {
        int x , y;
        cin >> x >> y;
        a.push_back(MP(x - 1, y - 1));
    }
    a.push_back(MP(h - 1, w - 1));
    sort(ALL(a));
    
    FOR(i,0,a.size())
    {
        dp[i] = C(a[i].first + a[i].second, a[i].first);
        FOR(j,0,i)
        {
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
            {
                dp[i] = (dp[i] - dp[j] * C(a[i].first - a[j].first + a[i].second - a[j].second , a[i].first - a[j].first) % MOD + MOD) % MOD;
            }
        }
    }
    
    cout << dp[a.size() - 1] << endl;
    
    return 0;
}