#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,k,p;
int dp[110][110][110];
struct FastMod {
	typedef unsigned long long ULL;
	typedef __uint128_t LLL;
	ULL b, m;
	void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
	ULL operator()(ULL a){
		ULL q = (ULL)((LLL(m) * a) >> 64);
		ULL r = a - q * b;
		return r >= b ? r - b : r;
	}
} M;
void addx(int &x,int y){
	x=(x+y>=p?x+y-p:x+y);
}
int C[110][110],fac[110];
int main(){
	n=read(),m=read(),k=read(),p=read();
	M.init(p);
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=M(1ll*fac[i-1]*i);
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		C[i][0]=1;
	}
	for(int i=1;i<=n;++i) dp[m][i][1]=fac[i];dp[m][0][0]=1;
	for(int i=m-1;i>=1;--i){
		dp[i][0][0]=1;
		for(int j=1;j+i-1<=n;++j){
			for(int l=0;l<=k&&l<=j;++l){
				// printf("%d %d %d\n",i,j,l);
				if(j==1&&l==0) dp[i][j][l]=1;
				else dp[i][j][l]=2ll*dp[i+1][j-1][l]%p;
				for(int t=1;t<=j-2;++t){
					for(int p=0;p<=l&&p<=t;++p){
						// printf("t:%d,p:%d\n",t,p);
						addx(dp[i][j][l],M(M(1ll*dp[i+1][t][p]*dp[i+1][j-t-1][l-p])*C[j-1][t]));
					}
				}
				// printf("dp[%d][%d][%d]=%d\n",i,j,l,dp[i][j][l]);
			}
		}
	}
	printf("%d\n",dp[1][n][k]);
}