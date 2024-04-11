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
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

ll n;

long double w, u, v, res;

ll x[10007];
ll y[10007];


inline bool na_prawo(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2-x2*y1>=0;
}

bool wszystkie_na_prawo(ll x2, ll y2)
{
    for(int i = 1; i <= n; ++i)
    {
        if(!na_prawo(x[i], y[i], x2, y2))
        {
            return 0;
        }
    }

    return 1;
}

long double czas_dotarcia(long double x1, long double y1)
{
    return y1/u + (x1-v*y1/u)/v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> w >> v >> u;

    for(int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];

        res = max(res, czas_dotarcia(x[i], y[i])+(w-y[i])/u);
    }

    if(wszystkie_na_prawo(v, u))
    {
        res = w/u;
    }

    res = max(res, w/u);

    cout << setprecision(10) << res;
}