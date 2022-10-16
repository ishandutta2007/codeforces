#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,x,y,a,b;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld\n%lld %lld",&x,&y,&a,&b);
		if(a*2<=b)
			cout<<(x+y)*a<<endl;
		else
			cout<<min(x,y)*b+abs(x-y)*a<<endl;
	}
	return 0;
} //1