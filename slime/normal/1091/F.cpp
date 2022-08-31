#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
ll l[maxn];
int tp[maxn];
int lid = 0;
ll lst[maxn]; 
ll mns[maxn];
char inp[maxn];
ll ans = 0;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &l[i]);
	scanf("%s", inp + 1);
	for(int i = 1; i <= n; i++)
		if(inp[i] == 'G') tp[i] = 1;
		else if(inp[i] == 'W') tp[i] = 0;
		else tp[i] = 2;
	int lpl = 0;
	tp[0] = 2;
	for(int i = 1; i <= n; i++)
	{
		if(tp[i] == 2)
		{
			lst[i] = lst[i - 1] - l[i];
			if(lst[i] < 0)
				l[lpl] += -lst[i], 
				lst[i] = 0;
		}
		else lst[i] = lst[i - 1] + l[i];
		if(tp[i] < tp[lpl])
			lpl = i;
	}
	for(int i = 1; i <= n; i++)
		if(tp[i] == 2)
			lst[i] = lst[i - 1] - l[i];
		else lst[i] = lst[i - 1] + l[i];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		if(tp[i] == 2) ans += l[i];
		else if(tp[i] == 1) ans += 5 * l[i];
		else ans += 3 * l[i];
	
	mns[n + 1] = lst[n];
	for(int i = n; i >= 1; i--)
		mns[i] = min(mns[i + 1], lst[i]);
	ll n1 = 0;
	for(int i = 1; i <= n; i++)
		if(tp[i] == 2) continue;
		else
		{	// 
			if(tp[i] == 0) continue;
			ll us = min(mns[i] - n1, l[i] * 2); // us / 2
			l[i] -= us;
			n1 += us;
			ans -= 2 * us;
		}
	
	for(int i = 1; i <= n; i++)
		if(tp[i] == 2)
			lst[i] = lst[i - 1] - l[i];
		else lst[i] = lst[i - 1] + l[i];
	
	mns[n + 1] = lst[n];
	for(int i = n; i >= 1; i--)
		mns[i] = min(mns[i + 1], lst[i]);
	n1 = 0;
	for(int i = 1; i <= n; i++)
		if(tp[i] == 2) continue;
		else
		{	// 
			if(tp[i] == 1) continue;
			ll us = min(mns[i] - n1, l[i] * 2); // us / 2
			l[i] -= us;
			n1 += us;
			ans -= us;
		}
	printf("%lld\n", ans);
	return 0;
}