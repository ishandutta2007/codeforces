#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
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
struct th
{
	int num, id;
	bool operator < (const th &a)const
	{
		if(num != a.num) return num > a.num;
		return id < a.id;
	 } 
 }p[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int x;
			scanf("%d", &x);
			p[i].num += x;
		}
		p[i].id = i;
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++)
		if(p[i].id == 1)
		{
			printf("%d\n", i);
			return 0;
		}
	return 0;
}