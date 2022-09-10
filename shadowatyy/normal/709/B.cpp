#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

ll n, a, x;

ll res1, res2;

vector<ll> p;

int main()
{
    scanf("%lld%lld", &n, &a);

    if(n==1)
    {
    	cout << 0;
    	return 0;
    }

    REP(i, n)
    {
    	scanf("%lld", &x);
    	p.pb(x);
    }

    sort(p.begin(), p.end());

    for(int i = 1; i < n-1; ++i)
    {
    	res1 += p[i]-p[i-1];
    }

    for(int i = 2; i < n; ++i)
    {
    	res2 += p[i]-p[i-1];
    }

    res1 += min(max(a-p[0], p[0]-a), max(a-p[n-2], p[n-2]-a));
    res2 += min(max(a-p[1], p[1]-a), max(a-p[n-1], p[n-1]-a));

    printf("%lld", min(res1, res2));
}