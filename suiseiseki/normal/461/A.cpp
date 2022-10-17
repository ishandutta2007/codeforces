#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 300000
int n,a[Maxn+5];
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	ll ans=sum;
	for(int i=1;i<n;i++){
		ans+=sum;
		sum-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}