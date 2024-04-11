#include <cstdio>
#include <cstring>
const int Maxn=21;
const int Mod=31607;
int n;
int l_n;
int a[Maxn+5][Maxn+5],b[Maxn+5][Maxn+5];
int inv[Mod+5];
void init(){
	inv[1]=1;
	for(int i=2;i<Mod;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int f[1<<Maxn|5];
int val[1<<Maxn|5][Maxn+1];
int row_mul[Maxn+5];
int cur_val[Maxn+5];
int sz[1<<Maxn|5];
int calc(){
	for(int i=0;i<n;i++){
		val[0][i]=1;
	}
	for(int i=0;i<n;i++){
		row_mul[i]=1;
		for(int j=0;j<n;j++){
			val[0][j]=1ll*val[0][j]*a[i][j]%Mod;
			row_mul[i]=1ll*row_mul[i]*a[i][j]%Mod;
		}
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=0;k<n;k++){
					val[i][k]=val[i^(1<<j)][k];
					val[i][k]=1ll*val[i][k]*inv[a[j][k]]%Mod;
				}
				break;
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		f[i]=1;
		for(int j=0;j<n;j++){
			f[i]=1ll*f[i]*(1-val[i][j]+Mod)%Mod;
		}
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				f[i]=1ll*f[i]*row_mul[j]%Mod;
			}
		}
	}
	int ans=0;
	int lst_val=1;
	for(int i=0;i<n;i++){
		int tmp_mul=1;
		for(int j=0;j<n;j++){
			tmp_mul=1ll*tmp_mul*a[j][i]%Mod;
		}
		ans=(ans+1ll*lst_val*tmp_mul)%Mod;
		lst_val=1ll*lst_val*(1-tmp_mul+Mod)%Mod;
	}
	for(int i=1;i<(1<<n);i++){
		sz[i]=sz[i-(i&(-i))]+1;
	}
	for(int i=1;i<(1<<n);i++){
		if(sz[i]&1){
			ans=(ans+f[i])%Mod;
		}
		else{
			ans=(ans-f[i]+Mod)%Mod;
		}
	}
	return ans;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		val[0][i]=1;
	}
	for(int i=0;i<n;i++){
		row_mul[i]=1;
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=1ll*a[i][j]*inv[10000]%Mod;
			b[i][j]=a[i][j];
		}
	}
	int ans=0;
	ans=(ans+calc())%Mod;
	memcpy(a,b,sizeof a);
	int tmp_val=1;
	for(int x=0,y=0;x<n;x++,y++){
		tmp_val=1ll*tmp_val*a[x][y]%Mod;
		a[x][y]=1;
	}
	ans=(ans+1ll*(1-calc()+Mod)*tmp_val)%Mod;
	memcpy(a,b,sizeof a);
	tmp_val=1;
	for(int x=0,y=n-1;x<n;x++,y--){
		tmp_val=1ll*tmp_val*a[x][y]%Mod;
		a[x][y]=1;
	}
	ans=(ans+1ll*(1-calc()+Mod)*tmp_val)%Mod;
	memcpy(a,b,sizeof a);
	tmp_val=1;
	for(int x=0,y=n-1;x<n;x++,y--){
		tmp_val=1ll*tmp_val*a[x][y]%Mod;
		a[x][y]=1;
	}
	for(int x=0,y=0;x<n;x++,y++){
		tmp_val=1ll*tmp_val*a[x][y]%Mod;
		a[x][y]=1;
	}
	ans=(ans-1ll*(1-calc()+Mod)*tmp_val%Mod+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}