#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=1000000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
int a[Maxn+5];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll f[Maxn+5][2];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][0]=a[i],f[i][1]=-a[i];
	}
	int len=0;
	for(int i=1;i<=m;i++){
		int b;
		scanf("%d",&b);
		len=gcd(len,b);
	}
	for(int i=1;i<=n-len;i++){
		ll val[2]={std::max(f[i][0]+f[i+len][0],f[i][1]+f[i+len][1]),std::max(f[i][1]+f[i+len][0],f[i][0]+f[i+len][1])};
		f[i+len][0]=val[0],f[i+len][1]=val[1];
	}
	ll sum[2]={0,0};
	for(int i=n;i>n-len;i--){
		sum[0]+=f[i][0],sum[1]+=f[i][1];
	}
	printf("%lld\n",std::max(sum[0],sum[1]));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}