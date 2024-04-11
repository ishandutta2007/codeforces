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

ll n, k, sum_c, sum_k, l, res, res_k;

bitset<100007> capital;

ll c[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];

        sum_c += c[i];
    }

    for(int i = 1; i <= k; ++i)
    {
        cin >> l;

        capital[l] = 1;

        sum_k += c[l];
    }

    for(int i = 1; i <= n; ++i)
    {
        if(capital[i])
        {
            res += c[i]*(sum_c-sum_k);
            res_k += c[i]*(sum_k-c[i]);
        }
    }

    res += res_k/2;

    for(int i = 1; i < n; ++i)
    {
        if(!capital[i] && !capital[i+1])
        {
            res += c[i]*c[i+1];
        }
    }

    if(!capital[n] && !capital[1])
    {
        res += c[n]*c[1];
    }

    cout << res;
}