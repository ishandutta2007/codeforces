#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL x,y,c[7]; int t;
void upd(LL &x,LL y){
	x=min(x,y);
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=6;i++) scanf("%lld",&c[i]);
		for(int it=1;it<=100;it++){
			upd(c[1],c[2]+c[6]);
			upd(c[2],c[1]+c[3]);
			upd(c[3],c[2]+c[4]);
			upd(c[4],c[3]+c[5]);
			upd(c[5],c[4]+c[6]);
			upd(c[6],c[5]+c[1]);
		}
		LL c1=c[1],c2=c[2],c3=c[3],c4=c[4],c5=c[5],c6=c[6];
		LL ans = 0;
		if(min(x,y)>=0) {
			ans=min(x,y)*c1;
			if(x>y) ans+=(x-y)*c6;
			else ans+=(y-x)*c2;
		}else
		if(max(x,y)<=0) {
			ans=abs(max(x,y))*c4;
			if(x>y) ans+=(x-y)*c5;
			else ans+=(y-x)*c3;
		}else if(x>=0&&y<=0){
			ans=c6*abs(x)+c5*abs(y);
		}else{
			ans=c3*abs(x)+c2*abs(y);
		}
		printf("%lld\n", ans);
	}
}