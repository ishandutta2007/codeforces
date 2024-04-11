#include<bits/stdc++.h>
using namespace std;
int a[233333];
long long s[233333];
int n,k;
int pos[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(s[k]<n)
	{
		cout<<-1<<endl;
		return 0;
	}
	pos[k+1]=n+1;
	for(int i=k;i>=1;i--)
	{
		pos[i]=min(pos[i+1]-1,n-a[i]+1);
		if(pos[i]>s[i-1]+1)pos[i]=s[i-1]+1;
		if(pos[i]<=0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=1;i<=k;i++)cout<<pos[i]<<' ';
	return 0;
}