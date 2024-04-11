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
int c[maxn];
int mn[maxn], mx[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		mn[i] = n + 1, mx[i] = 1, cin>>c[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		mn[c[i]] = min(mn[c[i]], i), 
		mx[c[i]] = max(mx[c[i]], i);
	for(int i = 1; i <= n; i++)
	{
		int l = 1;
		while(c[l] == i) l++;
		ans = max(ans, mx[i] - l);
		l = n;
		while(c[l] == i) l--;
		ans = max(ans, l - mn[i]);
	}
	cout<<ans<<endl;
	return 0;
}