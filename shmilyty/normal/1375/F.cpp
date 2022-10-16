#include<bits/stdc++.h>
#define int long long
using namespace std;
int a1,a2,t,x[4];
signed main()
{
	scanf("%lld %lld %lld",&x[1],&x[2],&x[3]);
	puts("First");
	puts("10000000000");
	fflush(stdout);
	scanf("%lld",&a1);
	x[a1]+=10000000000ll;
	t=x[a1]*3-x[1]-x[2]-x[3];
	cout<<t<<endl;
	fflush(stdout);
	scanf("%lld",&a2);
	x[a2]+=t;
	cout<<x[a1]-x[6-a1-a2]<<endl;
	return 0;
}