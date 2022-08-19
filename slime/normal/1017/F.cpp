#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
#define dv 12000000
#define ll long long
#define mod 998244353
using namespace std;
typedef unsigned int ui;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
bool bpr[dv];
int prs[maxn], prcnt;
int n, a, b, c, d;
ui ans;
void cal(ui x)
{
	ui ns = (ui)d + x * (ui)c + x * x * (ui)b + x * x * x * (ui)a;
//	if(x <= n)cout<<x<<" "<<ns<<endl;
	for(ll q = x; q <= n; q *= x)
		ans += ns * (ui)(n / q);
}
int main()
{
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for(int i = 2; i < maxn; i++)
		bpr[i] = 1;
	for(int i = 2; i < maxn; i++)
		if(bpr[i])
		{
			cal(i);
			prs[prcnt++] = i;
			for(int j = 2; j * i < maxn; j++)
				bpr[i * j] = 0;
		}
	int bg = maxn;
	while(bg < n)
	{
		for(int i = 0; i < dv; i++)
		{
			bpr[i] = 1;
			if((i + bg) % 6 != 1 && (i + bg) % 6 != 5)
				bpr[i] = 0;
		}
		for(int i = 0; i < prcnt; i++)
		{
			int st = (bg - 1) / prs[i] + 1;
			for(int t = 0; t < 2; t++)
			{
				int j = st, ed = 1 + 4 * t;
				while(j % 6 != ed) j++;
			//	if(j * prs[i] < bg) cout<<"WA"<<endl;
				for(; j * (ll)prs[i] < bg + dv; j += 6)
					bpr[j * prs[i] - bg] = 0;
			}
		}
		for(int i = 0; i < dv; i++)
			if(bpr[i])
				cal(bg + i);
		bg += dv;
	}
	printf("%u", ans);
	return 0;
}
/*
100000 1 2 3 4
*/