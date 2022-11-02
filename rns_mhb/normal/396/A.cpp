#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define M 600
#define N 40000
typedef __int64 ll;
const ll mod = 1000000007;
ll fac[N], fac_[N];
ll pow(ll x, int k){
	ll s=1, pw=x;
	while(k){
		if(k&1)s=s*pw%mod;
		pw=pw*pw%mod;
		k/=2;
	}
	return s;
}
int n;
int flag[N], p[N], pn;
int q[N], qn, d[N];

void init(){
	int i, j;
	p[0]=2, pn++;
	for(i=3; i<N; i+=2)if(!flag[i]){
		p[pn++]=i;
		for(j=i*i; j<N; j+=2*i)flag[j]=1;
	}
	fac[0]=fac_[0]=1;
	for(i=1; i<N; i++){
		fac[i]=fac[i-1]*i%mod;
		fac_[i]=pow(fac[i], mod-2);
	}
}

void doit(int x){
	int i, c=x, j;

	for(i=0; i<pn && p[i]*p[i]<=c; i++)if(c%p[i]==0){
		for(j=0; j<qn; j++)if(p[i]==q[j])break;
		if(j==qn)q[qn++]=p[i];
		while(c%p[i]==0)c/=p[i], d[j]++;
	}
	if(c==1)return;
	for(j=0; j<qn; j++)if(c==q[j])break;
	if(j==qn)q[qn++]=c;
	d[j]++;
}


int main(){
	init();
	int i, x;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		doit(x);
	}
	ll ans=1;
	for(i=0; i<qn; i++){
		ans = ans*fac[d[i]+n-1]%mod;
		ans = ans*fac_[n-1]%mod;
		ans = ans*fac_[d[i]]%mod;
	}
	printf("%I64d\n", ans);
	return 0;
}