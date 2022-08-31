#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
ll n, m, k;
ll p[maxn];
ll cal(ll a)
{
	return (a - 1) / k;
}
int main()
{
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++)
		scanf("%lld", &p[i]);
	int npl = 0;
	int t = 0;
	while(npl < m)
	{
		ll st = cal(p[npl + 1] - npl);
		int i = npl + 1;
		while(i <= m && cal(p[i] - npl) == st) i++;
		npl = i - 1;
		t++;
	}
	cout<<t<<endl;
	return 0;
}