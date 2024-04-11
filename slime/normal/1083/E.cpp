#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define ld long double
#define mod 998244353
using namespace std;
struct point
{
	ll x, y;
	point(){x = 0, y = 0;}
	point(ll a, ll b)
	{
		x = a, y = b;
	}
};
ld k(point a, point b)
{
	return (ld)(b.y - a.y) / (ld)(b.x - a.x);
}
point stack[maxn];
int fr = 0, ed = 0;
struct th
{
	int x, y;
	ll a;
	bool operator < (const th &k)const
	{
		return x < k.x;
	}
}p[maxn];
ll cal(point a, ll b)
{
	return a.y - a.x * b;
}
ll dp[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d%lld", &p[i].x, &p[i].y, &p[i].a);
	sort(p, p + n);
	ll ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		dp[i] = 0;
		if(fr < ed)
		{
			while(fr + 1 < ed && cal(stack[fr], p[i].x) < cal(stack[fr + 1], p[i].x)) fr++;
			dp[i] = max(dp[i], cal(stack[fr], p[i].x));
		}
		dp[i] += p[i].x * (ll)p[i].y - p[i].a;
		point n1 = point(p[i].y, dp[i]);
		while(ed - fr >= 2 && k(stack[ed - 1], n1) >= k(stack[ed - 2], stack[ed - 1])) ed--;
		stack[ed++] = n1;
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}