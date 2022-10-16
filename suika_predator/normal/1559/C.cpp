#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[1]==1)
		{
			cout<<n+1<<' ';
			for(int i=1;i<=n;i++)cout<<i<<" \n"[i==n];
		}
		else if(a[n]==0)
		{
			for(int i=1;i<=n;i++)cout<<i<<" ";
			cout<<n+1<<endl;
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i-1]==0&&a[i]==1)
				{
					for(int j=1;j<i;j++)
						cout<<j<<' ';
					cout<<n+1;
					for(int j=i;j<=n;j++)
						cout<<' '<<j;
					cout<<endl;
					break;
				}
			}
		}
	}
	return 0;
}