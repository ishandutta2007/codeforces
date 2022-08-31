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
const int MAXN=205;
db a[MAXN][MAXN];
const db eps=1e-10;
bool zero(db x){return fabs(x)<eps;}
void jie(int n){
	for(int i=1;i<n;++i){
		for(int k=i;k<n;++k)
		if(!zero(a[k][i])){
			for(int j=1;j<=n;++j)swap(a[i][j],a[k][j]);
			break;
		}
		if(zero(a[i][i]))continue;
		for(int j=n+1;j>=i;--j)a[i][j]/=a[i][i];
		for(int j=1;j<n;++j)if(i^j && !zero(a[j][i])){
			db _=-a[j][i];
			for(int k=1;k<=n;++k)a[j][k]+=_*a[i][k];
		}
	}
}
struct edge{
	int u,v,w;
}b[5005];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
		if(b[i].u!=1&&b[i].u!=n)a[b[i].u][b[i].v]++,a[b[i].u][b[i].u]--;
		if(b[i].v!=1&&b[i].v!=n)a[b[i].v][b[i].v]--,a[b[i].v][b[i].u]++;
	}
	a[n][n]=a[n][n+1]=a[1][1]=1;
	jie(n+1);
	db bei=123456789101112131415.;
	rep(i,1,m){
		db p=a[b[i].v][n+1]-a[b[i].u][n+1];
		bei=min(bei,fabs(1.*b[i].w/p));
	}
	if(zero(bei)||bei>100000000000000.)bei=0;
	db ans=0;
	rep(i,1,m)if(b[i].v==1||b[i].u==1)ans+=a[b[i].u*b[i].v][n+1]*bei;
	printf("%.7lf\n",ans);
	rep(i,1,m)printf("%.7lf\n",(a[b[i].v][n+1]-a[b[i].u][n+1])*bei);
	return 0;
}