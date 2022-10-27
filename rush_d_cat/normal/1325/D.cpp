#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
LL u,v;
void chk(int k) {
	LL tmp=v; int c[62]={0};
	for(int i=59;i>=0;i--){
		if(u>>i&1){
			tmp-=(1LL<<i); c[i]++;
			if(c[i]>k)return;
		}
	}
	if(tmp%2||tmp<0){
		printf("-1\n");exit(0);
	}
	tmp/=2;
	for(int i=59;i>=0;i--){
		LL lim;
		if(u>>i&1) lim=(k-1)/2; else lim=k/2;
		LL cnt=min(lim, tmp/(1LL<<i));
		tmp-=cnt*(1LL<<i); c[i]+=cnt*2;
		if(tmp==0) break;
	}
	if(tmp) return;
	LL A=0,B=0;
	printf("%d\n", k);
	for(int i=1;i<=k;i++){
		LL val=0;
		for(int j=59;j>=0;j--){
			if(c[j]){
				c[j]--; val|=(1LL<<j);
			}
		}
		printf("%lld ", val);
		A^=val,B+=val;
	}
	//printf("%lld %lld\n", A,B);
	exit(0);
}
int main() {
	cin>>u>>v;
	for(int k=0;;k++) chk(k);
}