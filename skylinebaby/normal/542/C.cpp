#include<bits/stdc++.h>
using namespace std;
int a[300];
int vis[300];
long long p[300];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	int mx = 0;
	int pos = 0;
	for(int i = 1;i<=n;i++)
 	{
 		int t = i;
 		int cnt = 1;
		while(!vis[t])
		{
			vis[t] = cnt++;
			t = a[t];
		}
		p[pos++] = cnt - vis[t];
		mx = max(mx,vis[t]-1);
		memset(vis,0,sizeof(vis));
	}
	long long ans = 1;
	for(int i = 0;i<pos;i++) ans = ans*p[i]/__gcd(ans,p[i]);
	if(mx) ans *= (mx+ans-1)/ans;
	printf("%lld\n",ans);
	return 0;
}