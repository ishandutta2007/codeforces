#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int fa[maxn], s[maxn], a[maxn], ms[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 2; i <= n; i++)
		cin>>fa[i];
	for(int i = 1; i <= n; i++)
		cin>>s[i], ms[i] = 1e9;
	for(int i = 1; i <= n; i++)
		ms[fa[i]] = min(ms[fa[i]], s[i]);
	for(int i = 1; i <= n; i++)
		if(s[i] == -1)
			if(ms[i] != 1e9) s[i] = ms[i];
			else s[i] = s[fa[i]];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		if(s[i] < s[fa[i]]) 
		{
			cout<<-1<<endl;
			return 0;
		}
		else ans += s[i] - s[fa[i]];
	cout<<ans<<endl;
	return 0;
}