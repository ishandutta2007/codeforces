#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define mod 1000000007
#define maxn 2000005
#define ll long long 
using namespace std;
int p[maxn];
int prs[maxn], prcnt;
vector<int> dv[maxn], dvs[maxn];
bool bpr[maxn];
int tms[maxn];
int tot[maxn];
int tp[maxn];
void push(int x)
{
	for(int i = 0; i < dv[x].size(); i++)
	{
		int ns = dvs[x][i];
		if(ns > tms[dv[x][i]])
			tms[dv[x][i]] = ns, tot[dv[x][i]] = 1;
		else if(ns == tms[dv[x][i]]) tot[dv[x][i]]++;
	}
//	cout<<"poush "<<x<<" "<<tms[7]<<" "<<dvs[42][2]<<endl;
}
bool check(int x)
{
	for(int i = 0; i < dv[x].size(); i++)
	{
		int ns = dvs[x][i];
		if(ns == tms[dv[x][i]] && tot[dv[x][i]] == 1)
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	sort(p, p + n);
	for(int i = 0; i < maxn; i++)
		bpr[i] = 1;
	for(int j = 2; j < maxn; j++)
	{
		if(!bpr[j]) continue;
		prs[prcnt++] = j;
		for(int k = 1; k * j < maxn; k++)
		{
			int ns = k * j;
			bpr[ns] = 0;
			dv[ns].push_back(j);
			int ntt = 0;
			while(!(ns % j)) ntt++, ns /= j;
			dvs[k * j].push_back(ntt);
		}
	}
//	cout<<"!@#!@#"<<endl;
	for(int i = n - 1; i >= 0; i--)
		if(tms[p[i]]) push(p[i] - 1), tp[i] = 1;
		else push(p[i]), tp[i] = 0;
	ll ans = 1;
	bool flag = 0;
	for(int i = n - 1; i >= 0; i--)
		flag |= check(p[i] - tp[i]);
	for(int i = 0; i < maxn; i++)
	{
		ll ns = 1;
		//if(tms[i]) cout<<i<<" "<<tms[i]<<endl;
		for(int j = 0; j < tms[i]; j++)
			ns = ns * i % mod;
		ans = ans * ns % mod;
	}
	if(flag) ans++;
	if(ans >= mod) ans -= mod;
	printf("%lld\n", ans);
	return 0;
}