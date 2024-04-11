#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
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
int n,m;
char mat[2][2010];
char str[2010];
int R[2][2010][2010];
int L[2][2010][2010];
int dp[2][2][2010][2010];
int qd[2010];
int Hz[2][2010],Hd[2][2010],Hs[2010],Hds[2010];
int d=29;
const int mod=1e9+7;
int qpow(int x,int k=mod-2){
	if(x==d) return qd[k];
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;x=1ll*x*x%mod;k>>=1;
	}
	return res;
}
int gethsh(int line,int l,int r){
	if(l<0||r<0||l>n||r>n) return -1;
	if(l<=r){
		return (Hz[line][r]-1ll*Hz[line][l-1]*qpow(d,r-l+1)%mod+mod)%mod;
	}
	else{
		return (Hd[line][r]-1ll*Hd[line][l+1]*qpow(d,l-r+1)%mod+mod)%mod;
	}
}
int geth(int l,int r){
	if(l<0||r<0||l>m||r>m) return -2;
	if(l<=r){
		return (Hs[r]-1ll*Hs[l-1]*qpow(d,r-l+1)%mod+mod)%mod;
	}
	else{
		return (Hds[r]-1ll*Hds[l+1]*qpow(d,l-r+1)%mod+mod)%mod;
	}
}
int T,ans;
void solve(){
	for(int i=1;i<=m;++i) Hs[i]=(1ll*Hs[i-1]*d%mod+str[i]-'a'+1)%mod;
	for(int i=m;i>=1;--i) Hds[i]=(1ll*Hds[i+1]*d%mod+str[i]-'a'+1)%mod;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=1;++j){
			for(int k=1;k<=m;++k){
				if(k==1) L[j][i][k]=(mat[j][i]==str[k]),R[j][i][k]=(mat[j][i]==str[m-k+1]),dp[1][j][i][k]=L[j][i][k];
				else if(!(k&1)){
//					printf("i:%d,j:%d,k:%d\n",i,j,k);
//					printf("%d %d\n",gethsh(j,i,i-k+1),geth(1,k));
					if(gethsh(j,i,i-(k>>1)+1)==geth(1,k>>1)&&gethsh(j^1,i-(k>>1)+1,i)==geth((k>>1)+1,k)) L[j][i][k]=dp[1][j^1][i][k]=1;
					if(gethsh(j,i,i+(k>>1)-1)==geth(m,m-(k>>1)+1)&&gethsh(j^1,i+(k>>1)-1,i)==geth(m-(k>>1),m-k+1)) R[j][i][k]=1;
				}
			}
		}
	}
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			(T+=L[i][j][m])%=mod;if(m>2) (T+=R[i][j][m])%=mod; 
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=0;i<2;++i){
			for(int l=1;l<=m;++l){
				for(int j=0;j<2;++j){
					if(!dp[i][j][k][l]) continue ;
					if(!i){
						if(mat[j^1][k]==str[l+1])  (dp[1][j^1][k][l+1]+=dp[i][j][k][l])%=mod;
					}
					if(mat[j][k+1]==str[l+1]) (dp[0][j][k+1][l+1]+=dp[i][j][k][l])%=mod;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<2;++k){
				if(R[k][i+1][j]){
					if(j!=1) (ans+=(dp[0][k^1][i][m-j]+dp[1][k^1][i][m-j])%mod)%=mod;
					else (ans+=(dp[0][k][i][m-j]+dp[1][k][i][m-j])%mod)%=mod;
				}
			}
		}
	}
}
int main(){
	qd[0]=1;
	for(int i=1;i<=2000;++i) qd[i]=1ll*qd[i-1]*d%mod;
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	n=read();
	for(int i=0;i<=1;++i){
		scanf("%s",mat[i]+1);
		n=strlen(mat[i]+1);
	}
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			Hz[i][j]=(1ll*Hz[i][j-1]*d%mod+mat[i][j]-'a'+1)%mod;
		}
		for(int j=n;j>=1;--j){
			Hd[i][j]=(1ll*Hd[i][j+1]*d%mod+mat[i][j]-'a'+1)%mod;
		}
	}
	scanf("%s",str+1);
	m=strlen(str+1);
	solve();
//	printf("%d\n",ans);
//	printf("T:%d\n",T);
	memset(dp,0,sizeof(dp));memset(L,0,sizeof(L));memset(R,0,sizeof(R));
	reverse(str+1,str+m+1);solve();
	
	printf("%d\n",ans+(T>>1));
}