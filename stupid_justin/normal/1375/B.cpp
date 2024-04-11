#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f;
const int mod=1e9+7;



int n,m;
int a[305][305];
int ans[305][305];
int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (i==1 || i==n)
				{
					if (j==1 || j==m) ans[i][j]=2;
					else ans[i][j]=3;
				} else
				if (j==1 || j==m) ans[i][j]=3;
				else ans[i][j]=4;
			}
		}
		bool flag=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if (a[i][j]>ans[i][j]) flag=0;
			}
		}
		if (flag)
		{
			cout<<"YES"<<endl;
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=m;j++)
				{
					cout<<ans[i][j]<<" ";
				}
				cout<<endl;
			}
		 } 
		 else
		 cout<<"NO"<<endl;
	}
}