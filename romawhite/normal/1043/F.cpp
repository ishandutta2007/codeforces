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
const int MAX = 300007;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 1000000007;

int p[MAX];
int a[MAX];
int d[MAX];
int r[MAX];

int convert(int x)
{
    int y = 1;
    while (x > 1)
    {
        int pp = p[x];
        while (x % pp == 0) x /= pp;
        y *= pp;
    }
    return y;
}

VI get(int x)
{
    VI c;
    while (x > 1)
    {
        int pp = p[x];
        while (x % pp == 0) x /= pp;
        c.push_back(pp);
    }
    return c;
}

int dp[64];
int val[64];

int main()
{
//            freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    for(int i = 2; i * i < MAX; ++i)
        if (!p[i])
            for(int j = i * i; j < MAX; j += i)
                if (!p[j])
                    p[j] = i;
    
    FOR(i,1,MAX)
    {
        if (p[i] == 0)
            p[i] = i;
    }
    
    
    
    
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        x = convert(x);
        if (x == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        d[x] ++;
        a[x] = 1;
    }
    
    FOR(i,1,MAX)
    {
        for(int j = 2 * i; j < MAX; j += i)
            d[i] += d[j];
    }
    
    FOR(i,1,MAX)
    {
        if (i != convert(i)) continue;
        
        VI c = get(i);
        
        FOR(mask , 0, 1 << SZ(c))
        {
            int val = 1;
            int coef = 1;
            FOR(j,0,SZ(c))
                if (mask & (1 << j))
                {
                    val *= c[j];
                    coef *= -1;
                }
            r[i] += d[val] * coef;
        }
    }
    
    
    int res = INF;
    
    FOR(i,1,MAX)
    {
        if (!a[i]) continue;
        
        VI c = get(i);
        
        FOR(mask , 0 , 1 << SZ(c))
        {
            dp[mask] = INF;
            val[mask] = 1;
            FOR(j,0,SZ(c))
            {
                if (mask & (1 << j))
                    val[mask] *= c[j];
            }
        }
        dp[0] = 1;
        
        
        
        FOR(mask , 1 , 1 << SZ(c))
        {
            for (int s=mask; s; s=(s-1)&mask)
            {
                if (r[val[s]] == 0) continue;
                dp[mask] = min(dp[mask] , dp[mask ^ s] + 1);
            }
        }
        
        res = min(res , dp[(1 << SZ(c)) - 1]);
        
    }
    
    if (res == INF) res = -1;
    cout << res << endl;
    
    
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}