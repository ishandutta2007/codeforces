#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,h;
	scanf("%d %d",&w,&h);
	int n = w + h; 
	long long ans = 1;
	for(int i = 0;i<n;i++) ans = (ans*2)%998244353;
	printf("%lld\n",ans);
}