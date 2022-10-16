#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <map>
#include <vector>
#include <cstdio>
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
const int Maxn=20;
const int Maxm=(1<<16);
const int Mod=998244353;
int f[Maxm+5],cnt_m[Maxm+5];
int frac[Maxn+5],inv_f[Maxn+5],inv[Maxn+5];
map<vector<int>,int> cnt;
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	inv[0]=inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int main(){
	init();
	int n,k,c;
	scanf("%d%d%d",&n,&k,&c);
	int x_sum=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		x_sum^=a;
		vector<int> d;
		for(int j=0;j<=k;j++){
			d.push_back(a^(a-j));
		}
		cnt[d]++;
	}
	for(int x=0;x<(1<<c);x++){
		vector<int> e;
		for(pair<vector<int>,int> tmp:cnt){
			vector<int> &d=tmp.first;
			int &t=tmp.second;
			int mask=0;
			for(int i=1;i<=k;i++){
				if(__builtin_parity(x&d[i])){
					mask|=(1<<(i-1));
				}
			}
			if(cnt_m[mask]==0){
				e.push_back(mask);
			}
			cnt_m[mask]+=t;
		}
		vector<int> g(k+1);
		g[0]=1;
		for(int mask:e){
			vector<int> a(k+1);
			a[0]=1;
			for(int i=1;i<=k;i++){
				if((mask>>(i-1))&1){
					a[i]=Mod-inv_f[i];
				}
				else{
					a[i]=inv_f[i];
				}
			}
			vector<int> pw(k+1);
			int t=cnt_m[mask];
			pw[0]=1;
			for(int i=1;i<=k;i++){
				int res=0;
				for(int j=0;j<i;j++){
					res=(res+1ll*pw[j]*a[i-j]%Mod*(i-j))%Mod;
				}
				res=1ll*res*t%Mod;
				for(int j=1;j<i;j++){
					res=(res+1ll*(Mod-a[j])*pw[i-j]%Mod*(i-j))%Mod;
				}
				pw[i]=1ll*res*inv[i]%Mod;
			}
			for(int i=k;i>0;i--){
				int res=0;
				for(int j=0;j<=i;j++){
					res=(res+1ll*pw[j]*g[i-j])%Mod;
				}
				g[i]=res;
			}
			cnt_m[mask]=0;
		}
		f[x]=1ll*g[k]*frac[k]%Mod;
	}
	for(int i=1;i<(1<<c);i<<=1){
		for(int j=0;j<(1<<c);j+=(i<<1)){
			for(int k=0;k<i;k++){
				int u=f[j+k],v=f[i+j+k];
				f[j+k]=(u+v)%Mod;
				f[i+j+k]=(u-v+Mod)%Mod;
			}
		}
	}
	int inv_n=1ll*quick_power(1<<c,Mod-2,Mod)*quick_power(n,Mod-1-k,Mod)%Mod;
	for(int i=0;i<(1<<c);i++){
		printf("%lld ",1ll*f[i^x_sum]*inv_n%Mod);
	}
	puts("");
    return 0;
}