#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,b,ans[51][51];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
				ans[i][l]=0;
		if(a*n!=b*m)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int c=0;
		for(int i=1;i<=n;i++)
			for(int l=1;l<=a;l++)
			{
				c=c%m+1;
				ans[i][c]=1;
			}
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=m;l++)
				cout<<ans[i][l];
			cout<<endl;
		}
	}
	return 0;
}