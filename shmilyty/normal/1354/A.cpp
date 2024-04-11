#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b,c,d;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		a-=b;
		if(a<=0)
		{
			cout<<b<<endl;
			continue;	
		}	
		if(c<=d)
		{
			puts("-1");
			continue;
		}
		cout<<b+(a+c-d-1)/(c-d)*c<<endl;
	} 
	return 0;
}