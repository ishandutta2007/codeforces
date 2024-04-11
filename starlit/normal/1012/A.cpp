#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200005
using namespace std;
int n,a[N];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n<<1;i++)
	scanf("%d",a+i);
	sort(a,a+(n<<1));
	ans=(a[n-1]-a[0])*1ll*(a[2*n-1]-a[n]);
	for(int i=1;i<n;i++)
	ans=min(ans,(a[2*n-1]-a[0])*1ll*(a[n+i-1]-a[i]));
	printf("%I64d",ans);
}