#include <bits/stdc++.h>
using namespace std;
const int N=102;
int a[N*N],p[N],ans[N][2];
int n,m,q,i,j,r,l,x;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;q=n*m;
	for (i=1;i<=q;i++) cin>>a[i];
	for (l=1;l<=n;l=r)
	{
		r=min(n+1,l+m-1);
		for (i=1;i<=q;i++) if (a[i]>=l&&a[i]<r&&~p[x=a[i]])
		{
			if (!p[x]) p[x]=i; else
			{
				ans[x][0]=p[x];ans[x][1]=i;
				p[x]=-1;
				for (j=l;j<r;j++) if (~p[j]) p[j]=0;
			}
		} 
	}
	for (i=1;i<=n;i++) cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	cout.flush();
}