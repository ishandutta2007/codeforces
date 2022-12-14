#include<bits/stdc++.h>
using namespace std;

int n,a[300005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n/2;i++)ans+=(a[i]+a[n+1-i])*(a[i]+a[n+1-i]);
	printf("%lld\n",ans);
	return 0;
}