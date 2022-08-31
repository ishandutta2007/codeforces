#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int N=105;
const int jsb=1000000007;
int f[N][N][N],g[N][N][N];
int n,m,kp;int c[N][N];int ans;
int main(){
	rep(i,0,N-1){
		c[i][0]=c[i][i]=1;
		rep(j,1,i-1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%jsb;
	}
	scanf("%d%d%d",&n,&m,&kp);n/=2;
	rep(i,1,n)f[i][i][1]=1;
	rep(i,2,min(n,m)+1){
		memset(g,0,sizeof g);
		rep(j,1,n)rep(k,1,j)rep(p,1,kp)if(f[j][k][p]){
			int tmp=f[j][k][p];
			ans=(ans+(m-i+1)*1ll*tmp)%jsb;
			rep(u,1,n-j){
				LL ff=c[u+k-1][k-1]*1ll*p;
				if(ff>kp)break;
				g[j+u][u][ff]=(g[j+u][u][ff]+tmp)%jsb;
			}
		}
		rep(j,1,n)rep(k,1,j)rep(p,1,kp)f[j][k][p]=g[j][k][p];
	}
	printf("%d\n",ans);
	return 0;
}