#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a,k,cnt;
int add()
{
	int maxx=0,minn=114514114514114514,b=a;
	while(b)
	{
		maxx=max(maxx,b%10);
		minn=min(minn,b%10);
		b/=10;
	}
	return maxx*minn;
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&k);
		for(int i=1;i<k;i++)
		{
			int ad=add();
			if(ad==0)
				break;
			a+=ad;
		}
		cout<<a<<endl;
	}
	return 0;
}//114514