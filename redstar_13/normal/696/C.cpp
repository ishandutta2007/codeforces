#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long INT;

int power(int a, INT b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}
#define NN 100010
INT a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int k;
	scanf("%d",&k);
	int p=2,add=-1;
	for(int i=1;i<=k;i++){
		scanf("%I64d",&a[i]);
		p=power(p,a[i],mod);
		if(a[i]%2==0) add=1;
	}
	p=(INT)p*power(2,mod-2,mod)%mod;
  	int q=(p+add+mod)%mod;
  	q=(INT)q*power(3,mod-2,mod)%mod;
  	printf("%d/%d\n",q,p);
    return 0;
}