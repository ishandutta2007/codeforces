#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 100005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
ll b[maxn];
ll a[61][maxn];
int cnt[61];
ll ns[maxn];
ll ls[maxn];
int ncnt[61];
int main()
{
//	cout<<((ll)1 << (ll)60)<<endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d", &b[i]);
		for(int j = 60; j >= 0; j--)
			if(b[i] & ((ll)1 << (ll)j))
			{
				a[j][cnt[j]++] = b[i];
				break;
			}	
	}	
	bool flag = 1;
	for(int j = 60; j >= 0; j--)
	{
		if(cnt[j] > ncnt[j] + 1) flag = 0;
		for(int k = 0; k < cnt[j]; k++)
			for(int l = 0; l < 61; l++)
				if(a[j][k] & (((ll)1 << (ll)l)))
					ncnt[l]++;
	}
	if(!flag)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	int nlen = 0;
	for(int i = 60; i >= 0; i--)
	{
		ll nnum = 0;
		int npl = 0;
		int aflen = 0;
		for(int j = 0; j < nlen; j++)
			ls[j] = ns[j];
		for(int j = 0; j <= nlen; j++)
		{
			if((!(nnum & ((ll)1 << (ll)i))) && npl < cnt[i])
				ns[aflen++] = a[i][npl], 
				nnum ^= ns[aflen - 1], 
				npl++;
			if(j == nlen) break;
			ns[aflen++] = ls[j];
			nnum ^= ns[aflen - 1];
		}
		nlen = aflen;
	}
	for(int i = 0; i < nlen; i++)
		printf("%I64d ", ns[i]);
	return 0;
}