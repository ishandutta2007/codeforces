#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define int long long
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
map<PII,bool>Map;
PII a[100010];
bool cmp(PII x,PII y){
	return x.fi-x.se>y.fi-y.se;
}
struct segtree{
	int k;
	PII tre[400010];
	void pushup(int p){
		tre[p]=min(tre[p<<1],tre[p<<1|1]);
	}
	void build(int p,int l,int r,int op){
		if(l==r){
			tre[p].fi=(op==0?a[l].fi:a[l].se);tre[p].se=l;
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid,op);
		build(p<<1|1,mid+1,r,op);
		pushup(p);
	}
	void del(int p,int l,int r,int pos){
		if(l==r){
			tre[p]=mp(2e9,-1);return ;
		}
		int mid=l+r>>1;
		if(pos<=mid) del(p<<1,l,mid,pos);
		else del(p<<1|1,mid+1,r,pos);
		pushup(p);
	}
	PII query(int p,int l,int r,int L,int R){
		if(L>R) return mp(2e9,-1);
		if(l>=L&&r<=R) return tre[p];
		PII res=mp(2e9,-1);
		int mid=l+r>>1;
		if(L<=mid) res=min(res,query(p<<1,l,mid,L,R));
		if(R>mid) res=min(res,query(p<<1|1,mid+1,r,L,R));
		return res;
	}
}T[2];
set<int>col,row;
int d[100010];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		Map[mp(x,y)]=1;
		a[i]=mp(x,y);
	}a[++n]=mp(1e9+1,1e9+1);a[++n]=mp(0,0);
	sort(a+1,a+n+1,cmp);
//	printf("\n");
//	for(int i=1;i<=n;++i) printf("%d %d\n",a[i].fi,a[i].se);
//	printf("\n");
	for(int i=1;i<=n;++i) d[i]=a[i].se-a[i].fi;
	T[0].build(1,1,n,0);T[1].build(1,1,n,1);
	int det=0;
	for(int i=1;i<=n;++i){
		int pos=lower_bound(d+1,d+n+1,det)-d;
		PII ls=T[0].query(1,1,n,1,pos-1),rs=T[1].query(1,1,n,pos,n);
		ls.fi-=T[0].k,rs.fi-=T[1].k;
		PII res=min(ls,rs);
		int id=res.se;
		if(a[id].se-a[id].fi==det){
			if(!col.count(a[id].fi)&&!row.count(a[id].se))col.insert(a[id].fi),row.insert(a[id].se);
		} 
		else if(a[id].se-a[id].fi<det){
		if(!col.count(a[id].fi)){
			col.insert(a[id].fi);
			++T[0].k;--det;
		}
		} 
		else if(!row.count(a[id].se)){
			++det;++T[1].k;row.insert(a[id].se);
		}
		T[0].del(1,1,n,id);T[1].del(1,1,n,id);
	}
	Map[mp(0,0)]=1;
	vector<int>c,r;
	for(int x:col) c.pb(x);
	for(int x:row) r.pb(x);
	sort(c.begin(),c.end());sort(r.begin(),r.end());
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		if(Map.count(mp(x,y))){
			printf("LOSE\n");continue ;
		}
		if(col.count(x)||row.count(y)){
			printf("WIN\n");continue ;
		}
		int dx=lower_bound(c.begin(),c.end(),x)-c.begin();
		int dy=lower_bound(r.begin(),r.end(),y)-r.begin();
		x-=dx,y-=dy;
		if(x==y) printf("LOSE\n");
		else printf("WIN\n");
	}
	return 0;
}