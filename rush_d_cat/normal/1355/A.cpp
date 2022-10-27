#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int d(LL x) {
	int mx=0,mn=9;
	while(x){
		int t=x%10;
		mx=max(mx, t);
		mn=min(mn, t);
		x/=10;
	}
	return mx*mn;
}
int main() {
	/*
	int x=489;
	for(int i=1;i<=100;i++){
		printf("%d %d\n", x, d(x)); x+=d(x);
	}
	*/

	int t;
	scanf("%d", &t);
	while (t --) {
		LL x, k; scanf("%lld%lld",&x,&k);
		k --;
		for(int i=1;i<=k;i++){
			LL tmp=d(x);
			x+=tmp;
			if(tmp==0) break;
		}
		printf("%lld\n", x);
	}
}