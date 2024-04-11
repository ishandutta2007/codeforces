#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct segment_tree{
	int l,r,v,tag;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].v=max(t[ls(p)].v,t[rs(p)].v);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].v=t[p].tag=0;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void add_tag(int p,int v){
	ckmax(t[p].v,v),ckmax(t[p].tag,v);
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subseg){
		add_tag(p,v);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int query(int p,int l,int r){
	if(no_intersection)return 0;
	if(is_subseg)return t[p].v;
	push_down(p);
	return max(query(ls(p),l,r),query(rs(p),l,r));
}
int a[maxn],b[maxn],bl,l[maxn],m,n,r[maxn],t_case;
vector<int>p[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		for(ri i=1;i<=bl;++i)vector<int>().swap(p[i]);
		for(ri i=1;i<=n;++i)p[a[i]=lower_bound(b+1,b+bl+1,a[i])-b].push_back(i);
		build(1,1,n);
		for(ri i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),modify(1,x,y,y);
		for(ri i=1;i<=n;++i){
			ri j=upper_bound(p[a[i]].begin(),p[a[i]].end(),i)-p[a[i]].begin();
			if(j>=p[a[i]].size()||p[a[i]][j]>query(1,i,i))l[i]=1919810,r[i]=-114514;
			else l[i]=p[a[i]][j],r[i]=*prev(upper_bound(p[a[i]].begin(),p[a[i]].end(),query(1,i,i)));
		}
		ri ans=n,ansr=n;
		while(l[ansr]==1919810)--ansr;
		for(ri i=1,j=0,ansl=n+1;i<=n;++i){
			if(i>1)ckmin(ansl,l[i-1]),ckmax(j,r[i-1]);
			if(i>ansl)break;
			ckmin(ans,max(j,ansr)-i+1);
		}
		printf("%d\n",max(ans,0));
	}
	return 0;
}