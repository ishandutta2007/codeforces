#include <cstdio>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
typedef long long ll;
ll work(ll a,ll n,ll p){
	ll c=a*n/p;
	if(c==0){
		return max(a,p-a*n);
	}
	if(a*n%p<a*(p/a-1)){
		c--;
	}
	return work(min(a-p%a,p%a),c,a);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll a,n,p,h;
		scanf("%lld%lld%lld%lld",&a,&n,&p,&h);
		a%=p;
		ll ans=a*n<p?a:work(a,n,p);
		if(ans<=h){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
/*
I forget to submit it on LuoGu!
*/