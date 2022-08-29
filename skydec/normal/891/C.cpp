#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=510000;
int n,m,q;
struct edge{
	int u,v,w;
}a[N],b[N];
int t=1;
inline bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
struct query{
	int w,l,r,id;
}c[N];int tot;
inline bool cmp2(const query &a,const query &b){
	return a.w<b.w;
}
int fa[N];
int size[N];
int get(int x){
	while(fa[x]!=x)x=fa[x];
	return x;
}
bool ans[N];
pii req[N*20];
pii req2[N*20];
int vv;
bool Union(int x,int y,bool st=0){
	x=get(x);
	y=get(y);
	if(x==y)return 0;

	if(size[x]<size[y])swap(x,y);

	if(st){
		++vv;
		req[vv]=pii(y,y);
		req2[vv]=pii(x,size[x]);
	}
	size[x]+=size[y];
	fa[y]=x;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	scanf("%d",&q);
	rep(i,1,q){
		ans[i]=1;
		int k;scanf("%d",&k);
		rep(j,1,k){
			int x;scanf("%d",&x);
			b[t+j-1]=a[x];
		}
		sort(b+t,b+t+k,cmp);
		rep(l,t,t+k-1){
			int r=l;
			while(r<t+k-1&&b[r+1].w==b[l].w)++r;
			++tot;
			c[tot].l=l;
			c[tot].r=r;
			c[tot].w=b[l].w;
			c[tot].id=i;
			//printf("__%d %d %d %d\n",i,l,r,b[l].w);
			l=r;
		}
		t+=k;
	}
	sort(a+1,a+1+m,cmp);
	sort(c+1,c+1+tot,cmp2);
	rep(i,1,n)fa[i]=i,size[i]=1;

	int gt=0;
	rep(i,1,tot){
		while(gt<m&&a[gt+1].w<c[i].w){
			++gt;
			Union(a[gt].u,a[gt].v);
		}

		int L=c[i].l;
		int R=c[i].r;

		rep(j,L,R){
			if(!Union(b[j].u,b[j].v,1)){
				ans[c[i].id]=0;
				break;
			}
		}
		while(vv){
			fa[req[vv].fi]=req[vv].se;
			size[req2[vv].fi]=req2[vv].se;
			--vv;
		}
	}
	rep(i,1,q)if(ans[i])puts("YES");
	else puts("NO");
	return 0;
}