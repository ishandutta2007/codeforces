#include <cstdio>
#include <cstring>
const int Maxn=100;
const int Mod=1000000007;
const int Maxm=100000;
int n,q;
int c[Maxn+5],b[Maxn+5];
int f[Maxn+5][Maxn*Maxn+5],g[Maxn+5][Maxn*Maxn+5];
int sum_b[Maxn+5];
int ans[Maxm<<1|5];
int find_sum(int *s,int l,int r){
	if(l<=0){
		return s[r];
	}
	return (s[r]-s[l-1]+Mod)%Mod;
}
int main(){
	scanf("%d",&n);
	int all_c=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		all_c+=c[i];
	}
	for(int i=1;i<n;i++){
		scanf("%d",&b[i]);
		sum_b[i]=sum_b[i-1]+b[i];
	}
	for(int i=1;i<n;i++){
		sum_b[i]+=sum_b[i-1];
	}
	memset(ans,-1,sizeof ans);
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		int x;
		scanf("%d",&x);
		if(ans[x+Maxm]!=-1){
			printf("%d\n",ans[x+Maxm]);
			continue;
		}
		bool flag_1=0,flag_2=1;
		for(int i=1,sum_c=0;i<=n;i++){
			if(-sum_b[i-1]<i*x){
				flag_2=0;
			}
			sum_c+=c[i];
			if(sum_c-sum_b[i-1]<i*x){
				flag_1=1;
			}
		}
		if(flag_1){
			puts("0");
			continue;
		}
		if(flag_2){
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=1ll*ans*(c[i]+1)%Mod;
			}
			printf("%d\n",ans);
			continue;
		}
		f[0][0]=1;
		for(int i=0;i<=c[1];i++){
			g[0][i]=1;
		}
		for(int i=1,sum_c=c[1];i<=n;i++){
			for(int j=0;j<=sum_c;j++){
				f[i][j]=0;
				if(j-sum_b[i-1]<i*x){
					continue;
				}
				f[i][j]=find_sum(g[i-1],j-c[i],j);
			}
			sum_c+=c[i+1];
			g[i][0]=f[i][0];
			for(int j=1;j<=sum_c;j++){
				g[i][j]=(g[i][j-1]+f[i][j])%Mod;
			}
		}
		ans[x+Maxm]=g[n][all_c];
		printf("%d\n",g[n][all_c]);
	}
	return 0;
}