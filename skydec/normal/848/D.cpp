#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
const int N=65;
int n,m;
int f[N][N];
int g[N][N];
int inv[N<<1],fac[N<<1];
void initfac(int n){
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
}
int C(int a,int b){
	if(a<b)return 0;
	int ans=1;
	rep(i,0,b-1)ans=ans*1ll*(a-i)%P;
	return ans*1ll*inv[b]%P;
}
int main(){
	initfac(100);
	scanf("%d%d",&n,&m);

	g[0][1]=1;
	rep(i,1,n){
		rep(j,1,n+1){
			rep(k,0,i-1){
				int sum0=0;
				int sum1=0;
				rep(l,j+1,n+1){
					sum0=(sum0+g[k][l])%P;
					sum1=(sum1+g[i-1-k][l])%P;
				}
				int w=sum0*1ll*g[i-1-k][j]%P;
				w=(w+sum1*1ll*g[k][j])%P;
				w=(w+g[i-1-k][j]*1ll*g[k][j])%P;
				f[i][j]=(f[i][j]+w)%P;
			}
		}
		memset(g,0,sizeof g);
		g[0][1]=1;
		rep(d1,1,i)rep(d2,1,n+1)if(f[d1][d2]){
			per(d3,i,d1)per(d4,n+1,d2){
				int up=min(d3/d1,d4/d2);
				rep(c,1,up){
					int w=C((f[d1][d2]+c-1)%P,c);
					g[d3][d4]=(g[d3][d4]+g[d3-d1*c][d4-d2*c]*1ll*w)%P;
				}
			}
		}
	}
	printf("%d\n",g[n][m]);
	return 0;
}