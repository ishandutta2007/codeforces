#include <cstdio>
const int Maxn=500000;
const int Maxm=10000000;
const int Mod=1000000007;
int pow_2[Maxn+5];
bool np[Maxm+5];
int p[Maxm+5],p_len;
int mu[Maxm+5];
void init(){
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxm;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=-1;
		}
		for(int j=1,x;j<=p_len&&(x=i*p[j])<=Maxm;j++){
			np[x]=1;
			mu[x]=-mu[i];
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
		}
	}
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
int a[Maxm+5];
int n;
int g[Maxm+5],f[Maxm+5];
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=p_len;i++){
		for(int j=Maxm/p[i];j>0;j--){
			a[j]+=a[j*p[i]];
		}
	}
	for(int i=1;i<=Maxm;i++){
		g[i]=a[i]*mu[i];
	}
	for(int i=1;i<=p_len;i++){
		for(int j=1;j*p[i]<=Maxm;j++){
			g[j*p[i]]+=g[j];
		}
	}
	for(int i=1;i<=Maxm;i++){
		f[i]=(pow_2[a[i]]-1+Mod)%Mod;
	}
	for(int i=p_len;i>0;i--){
		for(int j=1;j*p[i]<=Maxm;j++){
			f[j]=(f[j]-f[j*p[i]]+Mod)%Mod;
		}
	}
	int ans=0;
	for(int i=2;i<=Maxm;i++){
		ans=(ans+1ll*f[i]*g[i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}