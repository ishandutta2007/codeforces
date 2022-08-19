#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long 
using namespace std;
int v[maxn];
ll t[maxn], s[maxn];
ll ans[maxn];
int dv[maxn];
void pls(int l, int r)
{
	dv[l]++, dv[r + 1]--;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &t[i]), s[i] = s[i - 1] + t[i];
	for(int i = 1; i <= n; i++)
	{
		if(s[n] - s[i - 1] <= v[i])
			pls(i, n);
		else
		{
			int l = i, r = n;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				ll nans = s[mid] - s[i - 1];
				if(nans >= v[i]) r = mid;
				else l = mid + 1;
			}
			pls(i, l - 1);
			v[i] -= (s[l - 1] - s[i - 1]);
			ans[l] += v[i];
		}
	}
	ll ntt = 0;
	for(int i = 1; i <= n; i++)
	{
		ntt += dv[i];
		ll nans = ntt * t[i] + ans[i];
		printf("%lld ", nans); 
	}
	return 0;
}