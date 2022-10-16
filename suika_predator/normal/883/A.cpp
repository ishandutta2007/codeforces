#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#define ll long long
using namespace std;
ll n,m,a,d;
ll t[100011];
int main()
{
	cin>>n>>m>>a>>d;
	for(int i=1;i<=m;++i)
		scanf("%I64d",&t[i]);
	ll laste=n*a;
	if(t[m]<n*a)t[++m]=n*a;
	ll p=d/a+1;
	ll last=0;
	ll ans=0;
	for(int i=1;i<=m;++i)
	{
		if(last<t[i])
		{
			ll ect=(min(t[i],laste)/a)-(last/a);
			if(ect<0)ect=0;
			ll rest=ect%p;
			if(ect>0)ans+=ect/p+!!rest;
			if(rest==0)rest=p;
			if(t[i]>=a&&(min(t[i],laste)/a-rest+1)*a>last)
			last=max(last,(min(t[i],laste)/a-rest+1)*a+d);
			if(last<t[i])
			{
				ans++; 
				last=t[i]+d;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}