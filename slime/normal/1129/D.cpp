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
int bl[maxn];
int dp[maxn];
int n, k;
int num[maxn];
int bg[sq], ed[sq], lz[sq];
int dv = 355;
int lb(int x)
{
	return x & (-x);
}
struct blk
{
	int lz, id;
	int sum[2 * sq];
	blk(){lz = 0;}
	void reb()
	{
		memset(sum, 0, sizeof(sum)); 
		for(int i = bg[id]; i <= ed[id]; i++)
			num[i] += lz;
		lz = 0;
		for(int i = bg[id]; i <= ed[id]; i++)
		{
			int ns = num[i] - k + sq;
			if(ns < 0) ns = 0;
			if(ns >= 2 * sq) ns = 2 * sq - 1;
			sum[ns] = (sum[ns] + dp[i]) % mod;
		}
		for(int i = 1; i < sq * 2; i++)
			sum[i] = (sum[i] + sum[i - 1]) % mod;
	}
	int q()
	{
		return sum[sq - lz];
	}
	void push(int s)
	{
		lz += s; 
		if(abs(lz) >= 300) reb();
	}
}block[sq];
void pls(int l, int r, int s)
{
	int ls = l;
	while(l <= r)
	{
		if(l != bg[bl[l]] || ed[bl[l]] > r)
			num[l] += s, l++;
		else block[bl[l]].push(s), l = ed[bl[l]] + 1;
	}
	block[bl[ls]].reb();
	if(bl[ls] != bl[r]) block[bl[r]].reb();
}
int q(int l, int r)
{
//	cout<<"Q"<<l<<" "<<r<<endl;
	int ans = 0;
	while(l <= r)
	{
		if(l != bg[bl[l]] || ed[bl[l]] > r)
		{
			if(num[l] + lz[bl[l]] <= k)
				ans = (ans + dp[l]) % mod;
			l++;
		}
		else
		{
			ans = (ans + block[bl[l]].q()) % mod;
			l = ed[bl[l]] + 1;
		}
	}
	return ans;
}
int fst[maxn], nxt[maxn];
int a[maxn];
int main()
{
	cin>>n>>k;
	for(int i = 1; i < sq; i++)
	{
		bg[i] = ed[i - 1] + 1, 
		ed[i] = min(n + 1, bg[i] + dv - 1);
		for(int s = bg[i]; s <= ed[i]; s++)
			bl[s] = i;
		block[i].id = i;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), fst[i] = nxt[i] = n + 1;
	dp[n + 1] = 1;
	block[bl[n + 1]].reb();
	for(int i = n; i >= 1; i--)
	{
		pls(i + 1, fst[a[i]], 1);
		pls(fst[a[i]] + 1, nxt[a[i]], -1);
		nxt[a[i]] = fst[a[i]], fst[a[i]] = i;
		dp[i] = q(i + 1, n + 1);
		block[bl[i]].reb();
	}
	dp[1] %= mod;
	if(dp[1] < 0) dp[1] += mod;
	cout<<dp[1]<<endl;
	return 0;
} 
/*
2 1 1 5

 
*/