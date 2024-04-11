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
#define N 2*1048576
#define MAXN 2*1000007
using namespace std;

int n, q;

int t[MAXN];

int p[MAXN];

int a[MAXN];
int b[MAXN];

int res[MAXN];

vector<PII> z[MAXN];

int load[2*N];

map<int, int> last;

void Insert(int a, int v)
{
    a += N;

    while(a>=1)
    {
        load[a] ^= v;

        a /= 2;
    }
}

int Query(int a, int b)
{
    int res = 0;

    a += N;
    b += N;

    res ^= load[a];

    if(a!=b)
        res ^= load[b];

    while(a<b-1)
    {
        if(a%2==0)
            res ^= load[a+1];

        if(b%2==1)
            res ^= load[b-1];

        a /= 2;
        b /= 2;
    }

    return res;
}


int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", t+i);

        p[i] = t[i]^p[i-1];
    }

    scanf("%d", &q);

    for(int i = 1; i <= q; ++i)
    {
        scanf("%d%d", a+i, b+i);

        z[b[i]].eb(a[i], i);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(last[t[i]])
            Insert(last[t[i]], t[i]);

        last[t[i]] = i;

        Insert(last[t[i]], t[i]);

        for(int j = 0; j < z[i].size(); ++j)
        {
            res[z[i][j].nd] = p[i]^p[z[i][j].st-1]^Query(z[i][j].st, i);
        }
    }

    for(int i = 1; i <= q; ++i)
    {
        printf("%d\n", res[i]);
    }
}