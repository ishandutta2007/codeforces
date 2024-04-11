#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define MP make_pair
bool mark1[1000000],mark2[1000000];
ll num1,num2;
int main()
{
	ll n,m,x,y;
	cin>>n>>m;
	num1=n;
	num2=n;
	for(ll i=0;i<m;i++)
	{
		cin>>x>>y;
		if(mark1[x]==0)
		{
			num1--;
			mark1[x]=1;
		}
		if(mark2[y]==0)
		{
			num2--;
			mark2[y]=1;
		}
		cout<<num1*num2<<" ";
	}
}
/*int main()
{
	ll i,n,s=0,j;
	cin>>n;
	ll a[n+10];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	s/=(n/2);
	for(i=0;i<n;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			for(j=i+1;j<n;j++)
			{
				if(a[i]+a[j]==s)
				{
				cout<<i+1<<" "<<j+1<<endl;
				mark[j]=1;
				break;
				}
			}
		}
	}
}*/