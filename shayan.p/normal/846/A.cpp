#include<bits/stdc++.h>
#define  pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define vll vector<ll>
#define vvll vector<vector<ll> >
typedef long long ll;
using namespace std;
int main()
{
ll n,i;
cin>>n;
ll ans=n;
bool a[n];
for(i=0;i<n;i++)
cin>>a[i];
bool p[n];
ll num[n];
p[0]=a[0];
num[0]=1;
ll h=0;
for(i=1;i<n;i++)
{
	if(a[i]==p[h])
	num[h]++;
	else
	{
	p[h+1]=!p[h];
	num[++h]=1;
	}
}
ll Min=1e10;
bool check=0;
ll last_check=0;
for(i=0;i<=h;i++)
{
	if(p[i]==1)
	{
		last_check+=num[i];
		ans=0;
		check=1;
		for(ll j=0;j<i;j++)
		{
			if(p[j]==1)
			ans+=num[j];
		}
		for(ll j=i+1;j<=h;j++)
		{
			if(p[j]==0)
			ans+=num[j];
		}
	}
	Min=min(Min,ans);
}
Min=min(Min,last_check);
if(!check)
cout<<n;
else
cout<<n-Min;
}