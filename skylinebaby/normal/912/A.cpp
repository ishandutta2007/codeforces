#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int a,b;
	scanf("%lld %lld",&a,&b);
	int c,d,e;
	scanf("%lld %lld %lld",&c,&d,&e);
	int x = c * 2 + d;
	int y = d + 3 * e; 
	int ans = (x>a? x-a:0) + (y>b? y-b:0);
	printf("%lld\n",ans);
	return 0;
}