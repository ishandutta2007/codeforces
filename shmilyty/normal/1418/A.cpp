#include<bits/stdc++.h> 
#define int long long
using namespace std;
int t,x,y,k;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&x,&y,&k);
		y=(y+1)*k;
		cout<<(y-1+x-2)/(x-1)+k<<endl; 
	}
	return 0;
}