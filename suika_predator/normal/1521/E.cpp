#include<bits/stdc++.h>
using namespace std;
int a[777][777];
pair<int,int> num[111111];
queue<int> ord;
int main()
{
	int T,n,m,k;
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>m>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>num[i].first;
			num[i].second=i;
		}
		sort(num+1,num+k+1,greater<pair<int,int> >());
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=num[i].first;j++)
				ord.push(num[i].second);
		}
		n=0;
		while(n*n-(n/2)*(n/2)<m)n++;
		while(n*((n+1)/2)<num[1].first)n++;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=2;i<=n;i+=2)
		{
			for(int j=1;j<=n;j+=2)
			{
				if(!ord.empty())
				{
					a[i][j]=ord.front();
					ord.pop();
				}
			}
		}
		for(int i=1;i<=n;i+=2)
		{
			for(int j=1;j<=n;j+=2)
			{
				if(!ord.empty())
				{
					a[i][j]=ord.front();
					ord.pop();
				}
			}
		}
		for(int i=1;i<=n;i+=2)
		{
			for(int j=2;j<=n;j+=2)
			{
				if(!ord.empty())
				{
					a[i][j]=ord.front();
					ord.pop();
				}
			}
		}
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<a[i][j]<<" \n"[j==n];
			}
		}
	}
	
	return 0;
}