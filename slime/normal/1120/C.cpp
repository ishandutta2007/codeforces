#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
#define maxl 10005 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int s[maxl];
int rk[maxl], sa[maxl], cnt[maxl], a[maxl], b[maxl];
int len = 1;
void bogo_sort()
{
	int n = len;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[b[i]]++;
	for(int i = 1; i < maxl; i++)
		cnt[i] += cnt[i - 1];
	for(int i = 1; i <= n; i++)
		rk[i] = cnt[b[i]]--, sa[rk[i]] = i;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[a[i]]++;
	for(int i = 1; i < maxl; i++)
		cnt[i] += cnt[i - 1];
	for(int i = n; i >= 1; i--)
		rk[sa[i]] = cnt[a[sa[i]]]--;
	for(int i = 1; i <= n; i++)
		sa[rk[i]] = i;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]) cnt++;
		rk[sa[i]] = cnt;
	}
}
int h[maxl], height[maxl];

int st[22][maxl];
int lg2[maxl];
void initsuffix()
{
	int n = len;
	for(int i = 1; i <= n; i++)
		a[i] = s[i], b[i] = 1;
	bogo_sort();
	int l = 1;
	while(l < n)
	{
		for(int i = 1; i <= n; i++)
			a[i] = rk[i], b[i] = rk[i + l];
		bogo_sort();
		l <<= 1;
	}
	for(int i = 1; i <= n; i++)
	{
		h[i] = max(0, h[i - 1] - 1);
		while(i + h[i] <= n && s[i + h[i]] == s[sa[rk[i] + 1] + h[i]]) h[i]++;
	}
	for(int i = 1; i <= n; i++) height[i] = h[sa[i]];
	for(int i = 0; i < 22; i++)
		for(int j = 1; j <= n + 1 - (1 << i); j++)
		{
			if(!i) st[i][j] = height[j];
			else st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	for(int i = 0; i < 22; i++)
		for(int j = (1 << i); j <= n && j < (1 << (i + 1)); j++)
			lg2[j] = i;
}
int qmin(int a, int b)
{
	int l = b - a + 1;
	int bs = lg2[l];
	int ans = min(st[bs][a], st[bs][b - (1 << bs) + 1]);
	return ans;
}
int qsuffix(int l, int r)
{	// l, r 
	if(rk[l] > rk[r]) swap(l, r);
	int ans = qmin(rk[l], rk[r] - 1);
	return ans;	
}
char x[maxn];
int dp[maxn];
int main()
{
	cin>>len;
	int a, b;
	cin>>a>>b;
	scanf("%s", x + 1);
	for(int i = 1; i <= len; i++)
		s[i] = x[i] - '0';
	initsuffix();
	dp[len + 1] = 0;
//	cout<<len<<endl;
	for(int i = len; i >= 1; i--)
	{
		dp[i] = a + dp[i + 1];
		int mxs = 0;
		for(int j = 1; j < i; j++)
		{
			int nl = min(qsuffix(i, j), i - j);
			mxs = max(mxs, i + nl - 1);
		}
	//	cout<<i<<" "<<dp[i]<<" "<<mxs<<endl;
		for(int j = i; j <= mxs; j++)
			dp[i] = min(dp[i], b + dp[j + 1]);
	}
	cout<<dp[1]<<endl;
	return 0;
}