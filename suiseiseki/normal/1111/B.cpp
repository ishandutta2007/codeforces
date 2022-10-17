#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
ll sum[Maxn+5];
int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	double ans=0.0;
	for(int i=1;i<=n&&i<=m+1;i++){
		ans=max(ans,((sum[n]-sum[i-1])+min((long long)(n-i+1)*k,(long long)m-(i-1)))*1.0/(n-i+1));
	}
	cout.precision(20);
	cout<<ans<<endl;
	return 0;
}