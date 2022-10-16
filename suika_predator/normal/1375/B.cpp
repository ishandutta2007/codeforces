#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int a[333][333],b[333][333];
inline bool chk(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int ok=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				b[i][j]=0;
				for(int d=0;d<4;d++)
				{
					b[i][j]+=chk(i+dx[d],j+dy[d]);
				}
				if(a[i][j]>b[i][j])ok=0;
			}
		}
		if(ok)
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					cout<<b[i][j]<<' ';
				}
				cout<<endl;
			}
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}