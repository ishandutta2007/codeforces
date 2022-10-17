#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
ll a[Maxn+5];
ll maxl[Maxn+5],maxr[Maxn+5];
ll sum[Maxn+5];
ll l[Maxn+5],r[Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxl[i]=maxl[i-1]+a[i];
		sum[i]=sum[i-1]+a[i];
		if(maxl[i]<0){
			maxl[i]=0;
		}
	}
	ll ans=0;
	for(int i=n;i>0;i--){
		maxr[i]=maxr[i+1]+a[i];
		if(maxr[i]<0){
			maxr[i]=0;
		}
	}
	ll now=0;
	for(int i=1;i<=n;i++){
		now+=a[i];
		ans=mx(ans,now);
		if(now<0){
			now=0;
		}
	}
	now=0;
	for(int i=1;i<=n;i++){
		now=mx(now,maxl[i-1]-sum[i-1]*x);
		ans=mx(ans,maxr[i+1]+sum[i]*x+now);
	}
	cout<<ans<<endl;
	return 0;
}