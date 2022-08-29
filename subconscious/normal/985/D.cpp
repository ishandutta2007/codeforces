#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n,H;
ll cnt(ll x){
	if(x>ll(2.5e9))return ll(1e18)+1;
	if(x<=H)return x*(x+1)/2;
	x+=H-1;ll p=0;
	if(x&1)x/=2,p=(x+1)*(x+1);
	else x/=2,p=x*(x+1);
	return p-H*(H-1)/2;
}
int main(){
	scanf("%lld%lld",&n,&H);
	ll L=0,R=1e18;
	while(L+1<R){
		ll mid=L+R>>1;
		if(cnt(mid)<n)L=mid;else R=mid;
	}
	printf("%lld\n",R);
	//system("pause");
}