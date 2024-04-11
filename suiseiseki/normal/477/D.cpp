#include <cstdio>
#define Mod 1000000007
#define Inf (Mod-1)
#define Maxn 5000
char s[Maxn+5];
int f[Maxn+5][Maxn+5],f_sum[Maxn+5][Maxn+5];
int g[Maxn+5][Maxn+5],g_min[Maxn+5][Maxn+5];
int T[Maxn+5],S[Maxn+5];
int power[Maxn+5];
int Same[Maxn+5][Maxn+5];
bool check(int x,int y,int len){
	int t=Same[x][y];
	if(t>=len){
		return 1;
	}
	return T[x+t]<T[y+t];
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n=0;
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		T[i]=s[i]-'0';
	}
	power[0]=1;
	for(int i=1;i<=n;i++){
		S[i]=((S[i-1]<<1)+T[i])%Mod;
		power[i]=(power[i-1]<<1)%Mod;
	}
	for(int i=n;i>0;i--){
		for(int j=n;j>0;j--){
			if(T[i]==T[j]){
				Same[i][j]=Same[i+1][j+1]+1;
			}
			else{
				Same[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][0]=f_sum[i][0]=g[i][0]=g_min[i][0]=1;
		for(int j=1,k;j<i;j++){
			g[i][j]=g_min[i][j]=Inf;
			if(T[j+1]){
				k=j-(i-j);
				if(k<-1){
					k=-1;
				}
				f[i][j]=f_sum[j][k+1];
				g[i][j]=mn(g[i][j],g_min[j][k+1]+1);
				g[i][j]%=Mod;
				if(k!=-1&&T[k+1]&&check(k+1,j+1,i-j)){
					f[i][j]+=f[j][k];
					f[i][j]%=Mod;
					g[i][j]=mn(g[i][j],g[j][k]+1);
					g[i][j]%=Mod;
				}
			}
		}
		g_min[i][i]=Inf;
		for(int j=i-1;j>=0;j--){
			f_sum[i][j]=f_sum[i][j+1]+f[i][j];
			f_sum[i][j]%=Mod;
			g_min[i][j]=mn(g[i][j],g_min[i][j+1]);
		}
	}
	int ans=Inf;
	for(int i=1;i<=mn(16,n);i++){
		ans=mn(ans,(g[n][n-i]+(int)(((S[n]-1ll*S[n-i]*power[i]%Mod)%Mod+Mod)%Mod)))%Mod;
	}
	if(ans==Inf){
		for(int i=17;i<=n;i++){
			if(g[n][n-i]!=Inf){
				ans=g[n][n-i]+(int)(((S[n]-1ll*S[n-i]*power[i]%Mod)%Mod+Mod)%Mod);
				ans%=Mod;
				break;
			}
		}
	}
	printf("%d\n%d\n",f_sum[n][0],ans);
	return 0;
}