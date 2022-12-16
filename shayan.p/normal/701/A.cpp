#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define MP make_pair
bool mark[1000000];
int main()
{
	ll i,n,s=0,j,avg;
	cin>>n;
	ll a[n+10];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	avg=s/(n/2);
	for(i=0;i<n;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
			for(j=i+1;j<n;j++)
			{
				if(a[i]+a[j]==avg&&!mark[j])
				{
				cout<<i+1<<" "<<j+1<<endl;
				mark[j]=1;
				break;
				}
			}
		}
	}
}