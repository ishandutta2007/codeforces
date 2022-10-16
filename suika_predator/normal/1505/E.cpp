#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m;
char s[11][11];
int disr[11][11],disd[11][11];
int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>(s[i]+1);
	}
	memset(disr,0x3f,sizeof(disr));
	memset(disd,0x3f,sizeof(disd));
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(s[i][j]=='*')
			{
				disr[i][j]=disd[i][j]=0;
			}
			else
			{
				disr[i][j]=min(disr[i][j+1]+1,inf);
				disd[i][j]=min(disd[i+1][j]+1,inf);
			}
		}
	}
	int x=1,y=1;
	int ans=0;
	while(x<=n&&y<=m)
	{
		ans+=s[x][y]=='*';
		if(disr[x][y+1]<=disd[x+1][y])y++;
		else x++;
	}
	cout<<ans<<endl;
	return 0;
}