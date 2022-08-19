#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define mod 1000000007
using namespace std;
int a[maxn];
int t;
int stack[maxn], top;
int fr[maxn], ed[maxn];
ll ans = 0;
void work1()
{
//	for(int i = 1; i <= t; i++)
//		cout<<a[i]<<endl;
	top = 0;
	for(int i = 1; i <= t; i++)
	{
		while(top && a[stack[top - 1]] <= a[i]) top--;
		if(!top) fr[i] = 0;
		else fr[i] = stack[top - 1];
		stack[top++] = i;
	}
	top = 0;
	for(int i = t; i >= 1; i--)
	{
		while(top && a[stack[top - 1]] < a[i]) top--;
		if(!top) ed[i] = t + 1;
		else ed[i] = stack[top - 1];
		stack[top++] = i;
	}
	for(int i = 1; i <= t; i++)
	{
		ans += 1ll * a[i] * (i - fr[i]) % mod * (ed[i] - i) % mod;
		ans %= mod;
	}
}
int b[maxn];
int c[maxn];
int q[maxn], frs, eds;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = n; i >= 1; i--)	
	{
		while(eds > frs && b[q[eds - 1]] <= b[i]) eds--;
		q[eds++] = i;
	//	cout<<frs<<" "<<eds<<" "<<b[q[1]]<<" "endl;
		while(frs < eds && q[frs] >= i + k) frs++;
		if(i <= n - k + 1)
			c[i] = b[q[frs]];
	}
//	cout<<c[1]<<" "<<c[2]<<endl;
	for(int i = 1; i <= k - 1; i++)
	{
		t = 0;
		int pl = i;
		while(pl <= n - k + 1)
			a[++t] = c[pl], 
			pl += k - 1;
		work1();
	}
	printf("%lld\n", ans);
	return 0;
}