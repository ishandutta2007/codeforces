#include <cstdio>
#include <vector>
#include <algorithm>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
typedef long long ll;
const int Maxn=400000;
const int Mod=998244353;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,m;
struct Edge{
	int u,v;
}edge[Maxn+5];
std::pair<int,int> a[Maxn+5];
std::vector<int> ans;
namespace BIT{
	int f[Maxn+5];
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]+=a;
		}
	}
}
int fac[Maxn+5],inv_f[Maxn+5];
int get(int x){
	int ans=0;
	for(int i=17;i>=0;i--){
		if((ans+(1<<i))<=n&&x>(1<<i)-BIT::f[ans+(1<<i)]){
			ans+=(1<<i);
			x-=(1<<i)-BIT::f[ans];
		}
	}
	return ans+1;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&edge[i].u,&edge[i].v);
	}
	for(int i=m;i>0;i--){
		a[i].first=get(edge[i].v);
		a[i].second=i;
		BIT::add(a[i].first,1);
	}
	for(int i=m;i>0;i--){
		BIT::add(a[i].first,-1);
	}
	std::sort(a+1,a+1+m);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i!=m&&a[i].first+1==a[i+1].first&&a[i].second<a[i+1].second){
			continue;
		}
		else if(a[i].first==n){
			continue;
		}
		else{
			cnt++;
		}
	}
	cnt=n-1-cnt;
	int ans=C(cnt+n,cnt);
	printf("%d\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}