#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p, f, cs, cw, s, w;
int main() {
	int t; scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld%lld%lld%lld%lld",&p,&f,&cs,&cw,&s,&w);
		LL res=0;
		for(LL x=0;x<=cs;x++){
			if(x*s<=p){
				LL y=min((p-x*s)/w, cw);
				LL tmp=x+y;
				//printf("x=%d,y=%d\n", x,y);
				LL r1=cs-x; LL t1=s;
				LL r2=cw-y; LL t2=w;
				if(t1>t2){
					swap(t1,t2); swap(r1,r2);
				}
				LL r1_ = min(f/t1, r1);
				LL rem = f - r1_ * t1;
				LL r2_ = min(rem/t2, r2);
				tmp += (r1_ + r2_);
				res = max(res, tmp);
			}
		}
		printf("%lld\n", res);
	}
}