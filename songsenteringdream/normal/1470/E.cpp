#include<cstdio>
#include<algorithm>
using namespace std;
const int o=5e5+10;
int T,n,k,q,p[o],m[o],z[o][6],y,tot[o];long long x;__int128 f[5][o],g[5][o];
inline void slv(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]),tot[m[p[i]]=i]=0;
	for(int i=0;i<=k;++i) for(int j=f[i][0]=1,$;j<=n;++j)
		for($=1,f[i][j]=f[i][j-1];$<=i&&$<j;++$) f[i][j]+=f[i-$][j-$-1];
	for(int i=1;i<=k;++i) for(int j=1,$;j<=n;++j)
		for(g[i][j]=g[i][j-1],$=1;$<=i&&j+$<=n;++$) if(p[j]>p[j+$]) g[i][j]+=f[i-$][n-j-$];
	for(int i=1;i<=n;sort(z[i],z[i]+tot[i]),++i)
		for(int j=0;j<=k&&i+j<=n;++j) z[i][tot[i]++]=p[i+j];
	for(int K=k,l,r,md,t;q--;K=k){
		scanf("%d%lld",&y,&x);
		if(x>f[k][n]){printf("-1\n");continue;}
		for(t=1;1;K-=l-t,t=l+1){
			for(l=t-1,r=n;l<r;)
				if(g[K][md=(l+r>>1)+1]-g[K][t-1]<x&&x<=g[K][md]-g[K][t-1]+f[K][n-md]) l=md;else r=md-1;
			if(l>=y){printf("%d\n",p[y]);break;}
			x-=g[K][l]-g[K][t-1];t=l+1;
			for(int i=0;i<tot[t];++i) if(m[z[t][i]]<=t+K)
				if(f[K-m[z[t][i]]+t][n-m[z[t][i]]]<x) x-=f[K-m[z[t][i]]+t][n-m[z[t][i]]];
				else{l=m[z[t][i]];break;}
			if(l>=y){printf("%d\n",p[t+l-y]);break;}
		}
	}
}
int main(){for(scanf("%d",&T);T--;slv());return 0;}