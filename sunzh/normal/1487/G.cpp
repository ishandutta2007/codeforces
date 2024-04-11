#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
const int mod=998244353;
int n;
int c[27];
int f[2][410][410][3][3];
bool fl;
int g[410][410],h[410][410];
int main(){
	n=read();
	for(int i=1;i<=26;++i){
		c[i]=read();
	}
	f[fl][0][0][0][0]=24*24;
	f[fl][1][0][0][1]=24;
	f[fl][1][0][1][0]=24;
	f[fl][0][1][0][2]=24;
	f[fl][0][1][2][0]=24;
	f[fl][0][2][2][2]=1;
	f[fl][2][0][1][1]=1;
	f[fl][1][1][1][2]=1;
	f[fl][1][1][2][1]=1;
	for(int i=3;i<=n;++i){
		fl^=1;
		for(int j=0;j<=i;++j){
			for(int k=0;j+k<=i;++k){
				for(int a=0;a<=2;++a){
					f[fl][j][k][a][0]=(23ll*f[fl^1][j][k][0][a]%mod+24ll*(f[fl^1][j][k][1][a]+f[fl^1][j][k][2][a])%mod)%mod;
					if(j) f[fl][j][k][a][1]=(f[fl^1][j-1][k][0][a]+f[fl^1][j-1][k][2][a])%mod;
					if(k) f[fl][j][k][a][2]=(f[fl^1][j][k-1][0][a]+f[fl^1][j][k-1][1][a])%mod;
				}
			}
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=0;i+j<=n;++j){
			for(int k=0;k<=2;++k){
				for(int l=0;l<=2;++l){
					(g[i][j]+=f[fl][i][j][k][l])%=mod;
				}
			}
		}
	}
	for(int i=n;i>=0;--i){
		for(int j=n;j>=0;--j){
			h[i][j]=(1ll*g[i][j]+h[i+1][j]+h[i][j+1]-h[i+1][j+1]+mod)%mod;
		}
	}
	int ans=h[0][0];
	for(int i=1;i<=26;++i) ans=(ans-h[c[i]+1][0]+mod)%mod;
	for(int i=1;i<=26;++i){
		for(int j=i+1;j<=26;++j){
			(ans+=h[c[i]+1][c[j]+1])%=mod;
		}
	}
	printf("%d\n",ans);
}