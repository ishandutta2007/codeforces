#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1005;
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
int f[N][N],g[N];
int n,S;
struct pla{int l,r,w,s,v,id;}a[N];
inline bool cmp(const pla &a,const pla &b){if(a.l^b.l)return a.l<b.l;return a.r>b.r;}
vector<pla>zh[N];
int main(){
	scanf("%d%d",&n,&S);
	rep(i,1,n){
		scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
		a[i].l++;a[i].r++;
	}
	sort(a+1,a+1+n,cmp);
	rep(i,1,n)a[i].id=i;
	rep(i,1,n)zh[a[i].l].pb(a[i]);
	
	per(i,n,1){
		int limit=a[i].s;
		if(S-a[i].w<limit)limit=S-a[i].w;
		
		rep(up,0,limit){
			rep(j,a[i].l,a[i].r)g[j]=0;
			rep(j,a[i].l,a[i].r){
				if(g[j-1]>g[j])g[j]=g[j-1];
				for(vector<pla>::iterator it=zh[j].begin();it!=zh[j].end();it++){
					pla u=*it;
					if(u.r>a[i].r)continue;
					if(u.w>up)continue;
					if(u.id<=i)continue;
					int pp=up-u.w;
					if(pp>u.s)pp=u.s;
					
					if(pp>=0)
					g[u.r]=Max(g[u.r],g[j]+f[u.id][pp]);
				}
			}
			f[i][up]=g[a[i].r]+a[i].v;
			if(up)if(f[i][up]<f[i][up-1])f[i][up]=f[i][up-1];
			
		}
	}
	
	int l=1;int r=2*n;
	memset(g,0,sizeof g);
	
	rep(i,l,r){
		if(g[i]<g[i-1])g[i]=g[i-1];
		for(vector<pla>::iterator it=zh[i].begin();it!=zh[i].end();it++){
			pla u=*it;
			int tmp=S-u.w;if(u.s<tmp)tmp=u.s;
			if(tmp>=0){
				g[u.r]=Max(g[i]+f[u.id][tmp],g[u.r]);
			}
		}
	}
	printf("%d\n",g[r]);
	return 0;
}