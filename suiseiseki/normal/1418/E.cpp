#include <cstdio>
#include <algorithm>
using namespace std;
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
const int Maxn=200000;
const int Mod=998244353;
int n,m;
int d[Maxn+5];
int sum_f[Maxn+5],sum_t[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	sort(d+1,d+1+n);
	for(int i=1;i<=n;i++){
		sum_f[i]=(sum_f[i-1]+d[i])%Mod;
	}
	for(int i=n;i>0;i--){
		sum_t[i]=(sum_t[i+1]+d[i])%Mod;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int pos=lower_bound(d+1,d+1+n,b)-d;
		int num=n-pos+1;
		if(num<a){
			puts("0");
			continue;
		}
		int ans=0;
		if(num>a){
			ans=(ans+1ll*sum_t[pos]*(num-a)%Mod*quick_power(num,Mod-2,Mod))%Mod;
		}
		ans=(ans+1ll*sum_f[pos-1]*(num+1-a)%Mod*quick_power(num+1,Mod-2,Mod))%Mod;
		printf("%d\n",ans);
	}
	return 0;
}