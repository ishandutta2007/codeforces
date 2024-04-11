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

int n;

ll res;

int c[100007];

string t[100007];

string revt[100007];

ll dp[100007];
ll revdp[100007];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];

        revt[i] = t[i];

        reverse(revt[i].begin(), revt[i].end());
    }

    for(int i = 1; i <= n; ++i)
    {
        dp[i] = INF;
        revdp[i] = INF;

        if(t[i].compare(t[i-1])>=0)
        {
            dp[i] = min(dp[i], dp[i-1]);
        }

        if(t[i].compare(revt[i-1])>=0)
        {
            dp[i] = min(dp[i], revdp[i-1]);
        }

        if(revt[i].compare(t[i-1])>=0)
        {
            revdp[i] = min(revdp[i], dp[i-1]+c[i]);
        }

        if(revt[i].compare(revt[i-1])>=0)
        {
            revdp[i] = min(revdp[i], revdp[i-1]+c[i]);
        }

    }

    res = min(dp[n], revdp[n]);

    if(res==INF)
    {
        cout << -1;
        return 0;
    }

    cout << res;


}