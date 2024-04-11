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
#define eb emplace_backA
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

ll n, m, result;

ll c[1000007];
ll cn[1000007];
ll res[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    FOR(i, 1, n)
    {
        cin >> c[i];
    }

    FOR(i, 1, m)
    {
        cin >> cn[i];
    }

    cn[0] = -INF;
    cn[m+1] = INF;

    FOR(i, 1, n)
    {
        res[i] = min(cn[lower_bound(cn, cn+m+1, c[i])-cn]-c[i], c[i]-cn[lower_bound(cn, cn+m+1, c[i])-cn-1]);

        result = max(result, res[i]);
    }

    cout << result;
}