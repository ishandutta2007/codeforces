#include<bits/stdc++.h>
using namespace std;
char a[101][101];
string s;
int t,n,m,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		ans=0;
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
				cin>>a[i][l];
		for(int i=1;i<n;i++)
			if(a[i][m]=='R')
				ans++;
		for(int l=1;l<m;l++)
			if(a[n][l]=='D')
				ans++;
		cout<<ans<<endl;
		
	}
	return 0;
}