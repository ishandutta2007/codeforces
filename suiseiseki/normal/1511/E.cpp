#include <vector>
#include <cstdio>
const int Maxn=300000;
const int Mod=998244353;
int n,m;
std::vector<char> s[Maxn+5];
int line_f[Maxn+5];
int pow_2[Maxn+5],inv_2[Maxn+5];
void init(){
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
	inv_2[0]=1;
	inv_2[1]=(Mod+1)>>1;
	for(int i=2;i<=Maxn;i++){
		inv_2[i]=1ll*inv_2[i-1]*inv_2[i]%Mod;
	}
	line_f[0]=1,line_f[1]=1;
	for(int i=2;i<=Maxn;i++){
		line_f[i]=(pow_2[i-1]+line_f[i-2])%Mod;
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	int all_num=0;
	for(int i=1;i<=n;i++){
		static char val[Maxn+5];
		scanf("%s",val+1);
		s[i].resize(m+1);
		for(int j=1;j<=m;j++){
			s[i][j]=val[j];
			if(s[i][j]=='o'){
				all_num++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int num=(s[i][1]=='o');
		for(int j=2;j<=m;j++){
			if(s[i][j]=='o'){
				num++;
			}
			else{
				num=0;
				continue;
			}
			if(s[i][j]=='o'&&s[i][j-1]=='o'){
				ans=(ans+1ll*pow_2[all_num-num]*line_f[num-2])%Mod;
			}
		}
	}
	for(int j=1;j<=m;j++){
		int num=(s[1][j]=='o');
		for(int i=2;i<=n;i++){
			if(s[i][j]=='o'){
				num++;
			}
			else{
				num=0;
				continue;
			}
			if(s[i][j]=='o'&&s[i-1][j]=='o'){
				ans=(ans+1ll*pow_2[all_num-num]*line_f[num-2])%Mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}