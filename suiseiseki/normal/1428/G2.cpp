#include <cstdio>
#include <cstring>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=999999;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int val[10];
const int pow_10[10]={1,10,100,1000,10000,100000,100000};
ll f[Maxn+5],g[Maxn+5];
int lis_1[Maxn+5],lis_1_len;
int lis_2[Maxn+5],lis_2_len;
int main(){
	int k;
	scanf("%d",&k);
	for(int i=0;i<6;i++){
		scanf("%d",&val[i]);
	}
	{
		int tmp=3*k;
		for(int i=0;(1<<i)<=tmp;i++){
			if(tmp>=(1<<i)){
				lis_1[++lis_1_len]=(1<<i);
				tmp-=(1<<i);
			}
		}
		if(tmp){
			lis_1[++lis_1_len]=tmp;
		}
	}
	{
		int tmp=3*(k-1);
		for(int i=0;(1<<i)<=tmp;i++){
			if(tmp>=(1<<i)){
				lis_2[++lis_2_len]=(1<<i);
				tmp-=(1<<i);
			}
		}
		if(tmp){
			lis_2[++lis_2_len]=tmp;
		}
	}
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<=Maxn;j++){
			g[j]=f[j];
		}
		for(int j=1;j<=lis_1_len;j++){
			if(3ll*lis_1[j]*pow_10[i]>Maxn){
				continue;
			}
			for(int k=Maxn-3*lis_1[j]*pow_10[i];k>=0;k--){
				f[k+3*lis_1[j]*pow_10[i]]=max(f[k+3*lis_1[j]*pow_10[i]],f[k]+1ll*lis_1[j]*val[i]);
			}
		}
		for(int j=1;j<=lis_2_len;j++){
			if(3ll*lis_2[j]*pow_10[i]>Maxn){
				continue;
			}
			for(int k=Maxn-3*lis_2[j]*pow_10[i];k>=0;k--){
				g[k+3*lis_2[j]*pow_10[i]]=max(g[k+3*lis_2[j]*pow_10[i]],g[k]+1ll*lis_2[j]*val[i]);
			}
		}
		for(int j=0;j<10;j++){
			for(int k=Maxn-j*pow_10[i];k>=0;k--){
				f[k+j*pow_10[i]]=max(f[k+j*pow_10[i]],g[k]);
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}