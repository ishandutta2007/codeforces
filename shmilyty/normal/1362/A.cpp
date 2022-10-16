#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b,diff;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		diff=0;
		if(a>b)
			swap(a,b);
		while(a<b)
		{
			a*=2;
			diff++;
		}
		if(a!=b)
		{
			puts("-1");
			continue;
		}
		cout<<(diff+2)/3<<endl;
	}
	return 0;
}