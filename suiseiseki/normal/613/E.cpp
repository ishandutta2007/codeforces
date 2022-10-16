#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=2000;
const int Mod=1000000007;
const int Base=131;
char ch[3][Maxn+5],t[Maxn+5];
ll Hash1[3][Maxn+5],Hash2[3][Maxn+5],Hasht[Maxn+5],bin[Maxn+5];
int n,m;
ll f[3][Maxn+5][Maxn+5],g[3][Maxn+5][Maxn+5],ans,gs;
ll get_1(int l,int r,int id){
	return Hash1[id][r]-Hash1[id][l-1]*bin[r-l+1];
}
ll get_2(int l,int r,int id){
	return Hash2[id][l]-Hash2[id][r+1]*bin[r-l+1];
}
ll merge(ll H1,ll H2,int len){
	return H2+H1*bin[len];
}
void dp(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=1;i<=m;i++){
		Hasht[i]=Hasht[i-1]*Base+(t[i]-'a'+1);
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k>0;k--){
				int len=((j-k+1)<<1);
				if(len>m){
					continue;
				}
				ll hash_a=get_1(k,j,i),hash_b=get_2(k,j,3-i),hash_h=Hasht[len];
				if(merge(hash_b,hash_a,j-k+1)==hash_h){
					if(len==m){
						gs++;
					}
					else{
						g[i][j][len]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(ch[i][j]==t[1]){
				g[i][j][1]=1;
			}
		}
	}
	for(int i=m;i>0;i--){
		Hasht[i]=Hasht[i+1]*Base+(t[i]-'a'+1);
	}
	for(int k=1;k<m;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=2;i++){
				if(g[i][j][k]){
					if(j<n&&ch[i][j+1]==t[k+1]){
						f[i][j+1][k+1]=(f[i][j+1][k+1]+g[i][j][k])%Mod;
					}
				}
				if(f[i][j][k]){
					if(j<n&&ch[i][j+1]==t[k+1]){
						f[i][j+1][k+1]=(f[i][j+1][k+1]+f[i][j][k])%Mod;
					}
					if(ch[3-i][j]==t[k+1]){
						g[3-i][j][k+1]=(g[3-i][j][k+1]+f[i][j][k])%Mod;
					}
				}
			}
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(ch[i][j]==t[m]){
				if(m==1){
					ans=(ans+1)%Mod;
				}
				ans=(ans+f[i][j-1][m-1])%Mod;
				ans=(ans+g[i][j-1][m-1])%Mod;
			}
			for(int k=j;k<=n;k++){
				int len=((k-j+1)<<1);
				ll hash_a=get_1(j,k,3-i),hash_b=get_2(j,k,i),hash_h=Hasht[m-len+1];
				if(merge(hash_a,hash_b,k-j+1)==hash_h){
					if(len==m&&m!=2){
						gs++;
					}
					else{
						ans=(ans+f[i][j-1][m-len])%Mod;
						ans=(ans+g[i][j-1][m-len])%Mod;
					}
				}
			}
		}
	}
}
signed main(){
	scanf("%s",ch[1]+1);
	scanf("%s",ch[2]+1);
	n=strlen(ch[1]+1);
	scanf("%s",t+1);
	m=strlen(t+1);
	bin[0]=1;
	int Lim=std::max(n,m);
	for(int i=1;i<=Lim;i++){
		bin[i]=bin[i-1]*Base;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			Hash1[i][j]=Hash1[i][j-1]*Base+(ch[i][j]-'a'+1);
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=n;j>0;j--){
			Hash2[i][j]=Hash2[i][j+1]*Base+(ch[i][j]-'a'+1);
		}
	}
	dp();
	std::reverse(t+1,t+m+1);
	dp();
	ans=(ans+(gs>>1))%Mod;
	if(m==1){
		ans>>=1;
	}
	printf("%lld\n",ans);
	return 0;
}