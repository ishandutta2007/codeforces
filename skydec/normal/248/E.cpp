#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
db f[110000][105];int up[110000],size[110000];
int n,q;db ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&up[i]);size[i]=up[i];f[i][up[i]]=1;if(!up[i])ans++;
	}
	scanf("%d",&q);
	while(q--){
		int u,v,k;scanf("%d%d%d",&u,&v,&k);
		ans-=f[u][0];int tmp=k;
		while(k--){
				rep(l,1,up[u]){
				f[u][l-1]+=f[u][l]*(l*1./size[u]);
				f[u][l]*=1.*((size[u]-l)*1./size[u]);
			}
			size[u]--;
		}
		ans+=f[u][0];size[v]+=tmp;
		printf("%.11lf\n",ans);
	}
	return 0;
}