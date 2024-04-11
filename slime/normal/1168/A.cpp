#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2000005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[maxn];	
int n, m;
int chk(int l, int r, int c)
{
	if(l >= c) return l;
	if(r < c) return maxn;
	return c;
}
bool check(int x)
{
	int mn = 0;
	for(int i = 1; i <= n; i++)
	{
		int nans = chk(a[i], min(a[i] + x, m - 1), mn);
		if(a[i] + x >= m)
			nans = min(nans, chk(0, a[i] + x - m, mn));
		if(nans == maxn) return 0;
		mn = nans; 
	}
	return 1;
}
int main()
{

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = m - 1;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}