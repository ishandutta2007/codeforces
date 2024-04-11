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

long double a, b, x, y, v, res = 1e9, d;

int n;

int main()
{
    cin >> a >> b >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> v;

        res = min(res, sqrt((a-x)*(a-x)+(b-y)*(b-y))/v);
    }

    cout << setprecision(20) << res;
}