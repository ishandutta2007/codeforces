#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pack{ll a,t,p;}A,B;
ll ans=1ll<<60;
int f,T,t0;
void sol(pack A,pack B){
	for(ll i=0;;++i){
		ll zans=A.a*i,ztim=A.t*A.a*i;
		if(ztim>=T){
			if(f*A.t<=T)ans=min(ans,i*A.p);
			return ;
		}
		if(zans>=f){
			ans=min(ans,i*A.p);
			return ;
		}
		ll rest=f-zans;
		ll tim=rest*t0;
		if(tim+ztim<=T){
			ans=min(ans,i*A.p);
			continue;
		}
		if(B.t>=t0)continue;
		ll used=(tim+ztim-T)/(t0-B.t);
		if((tim+ztim-T)%(t0-B.t))used++;
		ll tg=used/B.a;
//		printf("[%lld]",tg);
		if(used%B.a)tg++;
		if(tg*B.t*B.a+ztim>=T){
			if((f-zans)*B.t<=T-ztim)
				ans=min(ans,tg*B.p+i*A.p);
		} else {
			ans=min(ans,tg*B.p+i*A.p);
		}
	}
}
int main(){
	scanf("%d%d%d",&f,&T,&t0);
	scanf("%lld%lld%lld",&A.a,&A.t,&A.p);
	scanf("%lld%lld%lld",&B.a,&B.t,&B.p);
	if((ll)f*t0<=T){
		printf("0\n");
		return 0;
	}
	sol(A,B);
	sol(B,A);
	if(ans==(1ll<<60))printf("-1");
	else printf("%lld",ans);
}