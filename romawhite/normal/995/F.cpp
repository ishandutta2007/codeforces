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
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const Int INF2 = Int(INF) * 5000;
const Int INF3 = Int(INF) * INF;
const int MAX = 3007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

Int dp[MAX][MAX];
Int sd[MAX][MAX];

VI G[MAX];

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

Int fact[MAX];
Int dfact[MAX];

int main()
{
//    freopen("in.txt", "r", stdin);
    
    
    int n , d;
    cin >> n >> d;
    
    fact[0] = 1;
    dfact[0] = d;
    FOR(i,1,n + 1)
    {
        fact[i] = fact[i - 1] * i % MOD;
        dfact[i] = dfact[i - 1] * (d - i) % MOD;
    }
    
    
    
    FOR(i,1,n)
    {
        int x;
        cin >> x;
        --x;
        G[x].push_back(i);
    }
    
    RFOR(i,n,0)
    {
        FOR(j,1,n + 1)
        {
            dp[i][j] = 1;
            FOR(k,0,SZ(G[i]))
            {
                int to = G[i][k];
                dp[i][j] *= sd[to][j];
                dp[i][j] %= MOD;
            }
            sd[i][j] = sd[i][j - 1] + dp[i][j];
            sd[i][j] %= MOD;
        }
    }
    
    if (d <= n)
    {
        cout << sd[0][d] << endl;
        return 0;
    }
    
    Int res = 0;
    FOR(i,0,n + 1)
    {
        Int add = sd[0][i];
        if (add == 0) continue;
        add *= dfact[n];
        add %= MOD;
        add *= bpow(d - i , MOD - 2);
        add %= MOD;
        
        add *= bpow(fact[i] , MOD - 2);
        add %= MOD;
        add *= bpow(fact[n - i] , MOD - 2);
        if ((n - i) % 2 == 1)
            add = MOD - add;
            
        res += add;
        res %= MOD;
        
    }
    cout << res << endl;
    
    
    
}