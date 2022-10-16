#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 1000000
#define ll long long
int a[Maxn+5];
int n;
ll mn(ll a,ll b){
	return a<b?a:b;
}
ll work(ll k){
	ll sum=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		sum%=k;
		ans+=mn(sum,k-sum);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum==1){
		puts("-1");
		return 0;
	}
	ll ans=(1ll<<60);
	for(ll i=2;i*i<=sum;i++){
		if(sum%i==0){
			ans=mn(ans,work(i));
			while(sum%i==0){
				sum/=i;
			}
		}
	}
	if(sum>1){
		ans=mn(ans,work(sum));
	}
	cout<<ans<<endl;
	return 0;
}