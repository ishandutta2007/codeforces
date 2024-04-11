#include <cstdio>
#include <cstring>
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
const int Maxn=2000;
const int Maxk=50;
const int Mod=998244353;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int f[2][Maxk*2+5][Maxn+5];
int n,k;
int a[Maxn+5],b[Maxn+5];
int fac[Maxn+5],inv_f[Maxn+5];
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
int sum[Maxn*2+5];
int main(){
	init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a[i]=std::max(b[i]-k,0);
		b[i]=std::min(b[i]+k,i);
	}
	int cur=0,nxt;
	f[cur][0][0]=1;
	for(int i=1;i<=n;i++){
		nxt=cur^1;
		memset(f[nxt],0,sizeof f[nxt]);
		memset(sum,0,sizeof sum);
		for(int j=a[i],p=a[i-1]-1;j<=b[i];j++){
			while(p<b[i-1]&&p<j-1){
				p++;
				for(int k=0;k<i;k++){
					sum[p+k]=(sum[p+k]+1ll*fac[k]*f[cur][p-a[i-1]][k])%Mod;
				}
			}
			for(int k=0;k<=i;k++){
				int id=j-a[i];
				f[nxt][id][k]=1ll*sum[j+k-1]*inv_f[k]%Mod;
				if(a[i-1]<=j&&j<=b[i-1]){
					f[nxt][id][k]=(f[nxt][id][k]+f[cur][j-a[i-1]][k-1])%Mod;
					f[nxt][id][k]=(f[nxt][id][k]+1ll*f[cur][j-a[i-1]][k]*(j+k))%Mod;
				}
			}
		}
		cur=nxt;
	}
	int ans=0;
	for(int i=a[n];i<=b[n];i++){
		for(int j=0;i+j<=n;j++){
			ans=(ans+1ll*f[cur][i-a[n]][j]*fac[n-i]%Mod*inv_f[n-i-j])%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}