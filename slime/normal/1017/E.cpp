#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
#define ll long long
#define mod 998244353
using namespace std;
struct point
{
	ll x, y;
	point(){x = y = 0;}
	point(ll a, ll b)
	{
		x = a, y = b;
	}
	point operator - (point r)
	{
		return point(x - r.x, y - r.y);
	}
	void read()
	{
		scanf("%I64d%I64d", &x, &y);
	}
	bool operator < (const point &r)const
	{
		if(x != r.x) return x < r.x;
		return y < r.y;
	}
};
ll sqr(point a)
{
	return a.x * a.x + a.y * a.y;
}
ll mt(point a, point b)
{
	return a.y * b.x - b.y * a.x;
}
ll cr(point a, point b, point c)
{
	return mt(c - a, b - a);
}
ll sign(ll x)
{
	if(x > 0) return 1;
	else if(x == 0) return 0;
	else return -1;
}
int tp(point a, point b, point c)
{
	return sign(cr(a, b, c));
}
int n;
struct th
{
	ll x, y;
	bool operator == (th a)
	{
		return x == a.x && y == a.y;
	}
}ns[maxn];
struct x
{
//	x();
	int n;
	point ns[maxn];
	point ans[maxn];
	th cal[maxn];
	int k;
	void read()
	{
		k = 0;
		for(int i = 0; i < n; i++)
			ns[i].read();
	}
	void calc()
	{
		if(n <= 1)
		{
			k = n;
			for(int i = 0; i < n; i++)
				ans[i] = ns[i];
			return;
		}
		sort(ns, ns + n); 
		for(int i = 0; i < n; ans[k++] = ns[i++])
			while(k > 1 && tp(ans[k - 2], ans[k - 1], ns[i]) <= 0) --k;
		for(int i = n - 2, t = k; i >= 0; ans[k++] = ns[i--])
			while(k > t && tp(ans[k - 2], ans[k - 1], ns[i]) <= 0) --k;	
		k--;
	//	for(int i = 0; i < k; i++)
	//		cout<<ans[i].x<<" "<<ans[i].y<<endl;
	
//		while(1);
		for(int i = 0; i < k; i++)
			cal[i].x = sqr(ans[(i + 1) % k] - ans[i]), 
			cal[i].y = cr(ans[i], ans[(i + 1) % k], ans[(i + 2) % k]);
		//	cout<<cal[i].x<<" "<<cal[i].y<<endl;
			
	}
}c[2];
th nans[maxn], pr[maxn];
int nx[maxn];
int main()
{
	scanf("%d%d", &c[0].n, &c[1].n);
	c[0].read(), c[1].read();
	c[0].calc(), c[1].calc();
	if(c[0].k != c[1].k)
	{
		printf("NO\n");
		return 0;
	}
	int k = c[0].k;
	for(int i = 1; i <= 2 * k; i++)
		nans[i] = c[0].cal[(i - 1) % k];
	for(int i = 1; i <= k; i++)
		pr[i] = c[1].cal[i - 1];
	int ns = 0;
	nx[1] = 0;
	for(int i = 2; i <= k; i++)
	{
		while(ns && !(pr[ns + 1] == pr[i]))
			ns = nx[ns];
		if(pr[ns + 1] == pr[i])
			ns++;
		nx[i] = ns;
	//	cout<<i<<" "<<next[i]<<endl;
	}
	int i = 0, j = 0;
	while(i < k && j < 2 * k)
	{
	//	cout<<i<<" "<<j<<endl;
		if(pr[i + 1] == nans[j + 1])
			i++, j++;
		else
		{
			if(i) i = nx[i];
			else j++;
		}
	}
	if(i == k) printf("YES\n");
	else printf("NO\n");
	return 0;
}