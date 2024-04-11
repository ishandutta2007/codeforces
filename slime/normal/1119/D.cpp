#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 100005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
ll s[maxn];
ll dv[maxn];
ll sum[maxn];
const ll inf = 3e18; 
ll res[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>s[i];
	sort(s + 1, s + n + 1);
	s[n + 1] = inf;
	for(int i = 1; i <= n; i++)
		dv[i] = s[i + 1] - s[i];
	sort(dv + 1, dv + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + dv[i];
	int q;
	cin>>q;
	for(int i = 1; i <= q; i++)
	{
		ll l, r;
		cin>>l>>r;
		r -= l, r++;
		ll ans = 0;
		if(dv[1] > r) ans = 1ll * n * r;
		else
		{
			int ls = 1, rs = n;
			while(ls < rs)
			{
				int mid = (ls + rs) >> 1;
				if(dv[mid + 1] <= r) ls = mid + 1;
				else rs = mid;
			}
			ans = 1ll * (n - ls) * r;
			ans += sum[ls];
		}
		res[i] = ans;
	}
	for(int i = 1; i <= q; i++)
		printf("%lld ", res[i]);
	return 0;
} 
/*
2 1 1 5

 
*/