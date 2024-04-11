#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
typedef long long LL;
const int P=1000000007,N=505;
int n,m,ans,p[N],f[N][N],g[N][N]; LL z;
int main()
{
	scanf("%d%d",&n,&m); if (!m) return puts("1"),0;
	p[0]=1; rep(i,n) p[i+1]=p[i]*2%P; f[0][0]=1;
	rep(i,n){
		memset(g,0,sizeof(g));
		rep(j,m+1) rep(k,i+1) if (z=f[j][k]){
			g[j][k]=(g[j][k]+z*p[k])%P,
			g[j+1][i+1]=(g[j+1][i+1]+z*p[k]%P*(p[i-k+1]-1))%P;
		}
		memcpy(f,g,sizeof(f));
	}
	rep(k,n+1) ans=(ans+f[m][k])%P; printf("%d\n",(ans+P)%P);
	return 0;
}
//fuck fuck fuck!!!!!