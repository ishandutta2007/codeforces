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
const int inf = 2e9;
int a[maxn], b[maxn];
int main()
{
	int n, m, ta, tb, k;
	cin>>n>>m>>ta>>tb>>k;
	for(int i = 0; i < n; i++)
		cin>>a[i], a[i] += ta;
	for(int i = 0; i < m; i++)
		cin>>b[i];
	int ans = 0;
	for(int i = 0; i <= n; i++) 
		if(i > k) break;
		else
		{
			int ns = a[i];
			if(i == n) ans = inf;
			else
			{
				int u = lower_bound(b, b + m, a[i]) - b;
				u += (k - i);
				if(u >= m) ans = inf;
				else ans = max(ans, b[u]);
			}
		}
	if(ans == inf) cout<<-1<<endl;
	else cout<<ans + tb<<endl;
	return 0;
 }