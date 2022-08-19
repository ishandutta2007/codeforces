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
int d[maxn];
ll jc[maxn];
int main()
{
	jc[0] = 1;
	for(int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod;
	int n;
	cin>>n;
	for(int i = 1; i < n; i++)
		{
			int u, v;
			cin>>u>>v;
			d[u]++, d[v]++;
		}
	ll ans = n;
	for(int i = 1; i <= n; i++)
		ans = ans * jc[d[i]] % mod;
	cout<<ans<<endl;
	return 0;
 }