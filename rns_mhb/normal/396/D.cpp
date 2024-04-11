#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
#define M 1001001
const ll mod = 1000000007;
int t[M], a[M];
void add(int k){while(k<M)t[k]++, k+=(k&-k);}
int sum(int k, int s=0){while(k)s+=t[k], k-=(k&-k); return s;}
ll fac[M];

int main(){
	//freopen("huge.in", "r", stdin);
	//freopen("a.in", "r", stdin);
	int i, j, k, n, x, s;

	scanf("%d", &n);
	if(n<=2){
		scanf("%d", &x);
		printf("%d\n", x-1);
		return 0;
	}
	for(fac[0]=i=1; i<M; i++)fac[i]=fac[i-1]*ll(i)%mod;
	for(i=n; i; i--)scanf("%d", a+i);

	ll gas=1, ans=0;
	add(a[1]);
	for(i=2; i<=n; i++){
		x=a[i];
		s=sum(x);
		ll tmp=1ll*(i-1)*(i-2)/2;
			tmp=tmp%mod;
			tmp=tmp*tmp%mod;
			if(i>2)tmp=tmp*fac[i-3]%mod;
			tmp=s*tmp%mod;
			ans=(ans+tmp)%mod;
		tmp=gas*s%mod;
			ans=(ans+tmp)%mod;
		tmp=1ll*s*(s-1)/2;
			tmp%=mod;
			tmp=tmp*fac[i-1]%mod;
			ans=(ans+tmp)%mod;
		tmp=fac[i-1]*s%mod;
			gas=(gas+tmp)%mod;
		add(x);
	}

	printf("%I64d\n", ans);
	return 0;
}