#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 300000
int a[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=(n>>1);i++){
		ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	}
	cout<<ans<<endl;
	return 0;
}