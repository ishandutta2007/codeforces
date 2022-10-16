#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1111],b[1111];
vector<int> cur;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	if(n<=3)
	{
		cout<<0<<endl;
		return 0;
	}
	int maxx=0,maxp=0;
	for(int i=2;i<n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(j%i!=0&&j+i<n)
				cnt++;
		}
		if(cnt>maxx)maxx=cnt,maxp=i;
	}
	for(int j=1;j<=n;j++)
	{
		if(j%maxp!=0&&j!=n)
			b[j]=1;
//		cerr<<j<<' '<<b[j]<<endl;
	}
	for(int t=1;t<=n+5;t++)
	{
		cur.clear();
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1&&b[i]==1)
			{
				cur.push_back(i);
				a[i]=1;
			}
			if(cur.size()==maxp)break;
		}
		cout<<cur.size();
		if(cur.size()==0)return 0;
		for(auto x:cur)cout<<' '<<x;
		cout<<endl;
		int y;
		cin>>y;
		for(int i=0;i<cur.size();i++)
		{
			a[(y+i-1)%n+1]=0;
		}
	}
	cout<<0<<endl;
	return 0;
}