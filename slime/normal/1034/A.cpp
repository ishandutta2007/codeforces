#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 15000005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
bool bpr[maxn];
int mns[maxn];
int cnt[maxn], prcnt;
int x[300005];
int gcd(int x, int y)
{
	if(!y) return x;
	return gcd(y, x % y); 
}
void push(int x)
{
	while(x != 1)
	{
		int n1 = mns[x];
		cnt[n1]++;
		while(!(x % n1))
			x /= n1;
	}
}
int main()
{
	int n;
	for(int i = 0; i < maxn; i++)
		bpr[i] = 1;
	for(int j = 2; j < maxn; j++)
	{
		if(bpr[j])
			for(int k = 1; k * j < maxn; k++)
				bpr[j * k] = 0, mns[k * j] = j;
	} 
	scanf("%d", &n);
	int ns = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		ns = gcd(ns, x[i]);
	}
	for(int i = 1; i <= n; i++)
		x[i] /= ns;
	for(int i = 1; i <= n; i++)
		push(x[i]);
	int mxs = 0;
	for(int i = 0; i < maxn; i++)
		mxs = max(mxs, cnt[i]);
	if(mxs == 0) printf("-1\n");
	else printf("%d\n", n - mxs);
		
	return 0;
 }