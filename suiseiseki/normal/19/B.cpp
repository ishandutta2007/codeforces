#include <cstdio>
#include <cstring>
#define Maxn 2000
#define ll long long
ll f[Maxn<<1|5];
int t[Maxn+5],c[Maxn+5];
ll mn(ll a,ll b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t[i],&c[i]);
		f[i]=(1ll<<61);
		t[i]++;
		m=mx(m,t[i]);
	}
	m+=n;
	memset(f,0x3f,sizeof f);
	f[0]=0;
	ll ans=(1ll<<62);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=t[i];j--){
			f[j]=mn(f[j],f[j-t[i]]+c[i]);
			if(j>=n){
				ans=mn(ans,f[j]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}