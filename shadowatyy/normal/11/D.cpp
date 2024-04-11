#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int n, m, l, r;

ll res;

bitset<20> e[20];

vector<unsigned int> k;

int c(unsigned int a)
{
    return __builtin_popcount(a);
}

bool b(int p, unsigned int a)
{
    return (1<<p)&a;
}

int f(unsigned int a)
{
    return __builtin_ffs(a)-1;
}

bool comp(unsigned int a, unsigned int b)
{
    return __builtin_popcount(a)<__builtin_popcount(b);
}

ll dp[1<<19][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    while(m--)
    {
        cin >> l >> r;

        --l;
        --r;

        e[l][r] = 1;
        e[r][l] = 1;
    }

    for(int i = 0; i < (1<<n); ++i)
    {
        k.pb(i);
    }

    sort(k.begin(), k.end(), comp);

    for(int i = 0; i < (1<<n); ++i)
    {
        for(int v = 0; v < n; ++v)
        {
            if(b(v, k[i]) && c(k[i])==1)
                dp[k[i]][v] = 1;

            for(int u = 0; u < n; ++u)
            {
                if(e[u][v] && c(k[i])>1 && b(v, k[i]) && f(k[i])!=v)
                {
                    dp[k[i]][v] += dp[k[i]^(1<<v)][u];
                }
            }
        }
    }

    for(int i = 0; i < (1<<n); ++i)
    {
        for(int v = 0; v < n; ++v)
        {
            if(c(k[i])>2 && e[f(k[i])][v])
            {
                res += dp[k[i]][v];
            }
        }
    }

    cout << res/2;
}