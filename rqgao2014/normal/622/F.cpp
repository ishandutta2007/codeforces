#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define sqr(x) ((x)*(x))
#define FF first
#define SS second
#define debug(x) cerr<<#x<<"="<<x<<endl
#define debuge cerr<<"isok"<<endl
using namespace std;

const int N=2000005,mod=1e9+7;
int n,k,d,tot,f[N],fn[N],gn[N],fac[N],ifac[N],p[N];
bool vis[N];

int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);d=k+2;
	f[1]=1;
	for(int i=2;i<=d;i++){
		if(!vis[i])	p[++tot]=i,f[i]=exp(i,k);
		for(int j=1;j<=tot&&p[j]*i<=d;j++){
			vis[p[j]*i]=1;
			f[p[j]*i]=(ll)f[p[j]]*f[i]%mod;
			if(i%p[j]==0) break;
		}
	}
	for(int i=1;i<=d;i++) f[i]=(f[i-1]+f[i])%mod;
	if(n<=k+2){printf("%d\n",f[n]);return 0;}
	
	fac[0]=1;
	for(int i=1;i<=d;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[d]=exp(fac[d],mod-2);
	for(int i=d-1;~i;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
	fn[0]=gn[d+1]=1;
	for(int i=1;i<=d;i++) fn[i]=(ll)fn[i-1]*(n-i)%mod;
	for(int i=d;i;i--) gn[i]=(ll)gn[i+1]*(n-i)%mod;
	
	int ans=0;
	for(int i=1;i<=d;i++){
		int tmp=(ll)fn[i-1]%mod*gn[i+1]%mod*ifac[i-1]%mod*ifac[d-i]%mod*f[i]%mod;
		if(d-i&1) ans=(ans+mod-tmp)%mod; else ans=(ans+tmp)%mod;
	}
	printf("%d\n",ans);
}