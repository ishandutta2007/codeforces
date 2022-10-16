#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200;
const int Maxt=200;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,t,k;
int a[Maxn+5],b[Maxn+5],c[Maxn+5];
ll f[Maxn+5][Maxt+5][2],g[Maxn+5][Maxt+5][2];
int main(){
	scanf("%d%d%d",&n,&t,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	ll sum_a=0,sum_b=0;
	for(int i=1;i<=n+1;i++){
		sum_a+=a[i],sum_b+=b[i];
		f[i][0][0]=sum_b;
		g[i][0][0]=b[i];
		f[i][0][1]=sum_a;
		g[i][0][1]=a[i];
		for(int j=1;j<=t;j++){
			for(int t_y=0;t_y<2;t_y++){
				f[i][j][t_y]=g[i][j][t_y]=-Inf_ll;
				ll tmp=t_y?a[i]+1ll*b[i]*j:1ll*b[i]*(j+1);
				if(tmp<=c[i]&&g[i-1][j][t_y]>=0){
					f[i][j][t_y]=f[i-1][j][t_y]+tmp;
					g[i][j][t_y]=tmp;
				}
				for(int l=1;l<=j;l++){
					int r=t_y?(sum_a+sum_b*(l-1))%k:sum_b*l%k;
					if(i>n||(g[i][l-1][t_y]>=r&&r+1ll*b[i]*(j-l+1)<=c[i])){
						ll x=std::min(c[i]-1ll*b[i]*(j-l+1),g[i][l-1][t_y])-r;
						if(x<0&&x%k){
							x=x/k-1;
						}
						else{
							x=x/k;
						}
						x=x*k+r+b[i]*(j-l+1);
						if(g[i-1][j-l][0]>=0){
							f[i][j][t_y]=std::max(f[i][j][t_y],x+f[i-1][j-l][0]);
							g[i][j][t_y]=std::max(g[i][j][t_y],x);
						}
					}
				}
			}
		}
	}
	ll ans=(sum_a+sum_b*t-f[n+1][t][1])/k;
	printf("%lld\n",ans);
	return 0;
}