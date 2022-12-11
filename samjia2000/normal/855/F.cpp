#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int L = 1e5;
const int N = 50005;
const int INF = 1e9;

int q;
set<int>s0,s1;
struct node{
	int l,r,ad;
	LL sum;
	int fir,sec,fir_tot;
};
struct segment_tree{
	int tot,rt;
	node tree[L*2+5];
	
	void build(int &now,int l,int r,int v){
		tree[now=++tot].fir=v;
		tree[now].sec=0;
		tree[now].fir_tot=r-l+1;
		tree[now].sum=1ll*v*(r-l+1);
		tree[now].ad=INF;
		if (l==r)return;
		int mid=(l+r)/2;
		build(tree[now].l,l,mid,v);
		build(tree[now].r,mid+1,r,v);
	}
	
	void init(int l,int r,int v){
		rt=tot=0;
		build(rt,l,r,v);
	}
	
	void lazy_tag(int now,int v){
		tree[now].sum=tree[now].sum+1ll*(v-tree[now].fir)*tree[now].fir_tot;
		tree[now].fir=tree[now].ad=v;
	}
	
	void down(int now){
		if (tree[now].ad!=INF){
			int x=tree[now].l,ad=tree[now].ad;
			if (tree[x].fir>ad)lazy_tag(x,ad);
			x=tree[now].r;
			if (tree[x].fir>ad)lazy_tag(x,ad);
			tree[now].ad=INF;
		}
	}
	
	void update(int now){
		int l=tree[now].l,r=tree[now].r;
		tree[now].fir=max(tree[l].fir,tree[r].fir);
		tree[now].fir_tot=tree[now].sec=0;
		if (tree[l].fir==tree[now].fir)tree[now].fir_tot+=tree[l].fir_tot,tree[now].sec=max(tree[now].sec,tree[l].sec);
		else tree[now].sec=max(tree[now].sec,tree[l].fir);
		if (tree[r].fir==tree[now].fir)tree[now].fir_tot+=tree[r].fir_tot,tree[now].sec=max(tree[now].sec,tree[r].sec);
		else tree[now].sec=max(tree[now].sec,tree[r].fir);
		tree[now].sum=tree[l].sum+tree[r].sum;
	}
	
	void change1(int now,int l,int r,int x,int y,int v){
		if (x<=l&&r<=y){
			if (tree[now].fir<=v)return;
			if (tree[now].sec<=v){
				lazy_tag(now,v);
				return;
			}
			down(now);
			int mid=(l+r)/2;
			change1(tree[now].l,l,mid,x,y,v);
			change1(tree[now].r,mid+1,r,x,y,v);
			update(now);
			return;
		}
		down(now);
		int mid=(l+r)/2;
		if (x<=mid)change1(tree[now].l,l,mid,x,y,v);
		if (y>mid)change1(tree[now].r,mid+1,r,x,y,v);
		update(now);
	}
	
	void change2(int now,int l,int r,int x,int v){
		if (l==r){
			tree[now].sum=tree[now].fir=v;
			tree[now].fir_tot=1;
			tree[now].sec=0;
			return;
		}
		down(now);
		int mid=(l+r)/2;
		if (x<=mid)change2(tree[now].l,l,mid,x,v);
		else change2(tree[now].r,mid+1,r,x,v);
		update(now);
	}
	
	LL query(int now,int l,int r,int x,int y){
		if (x<=l&&r<=y)return tree[now].sum;
		down(now);
		int mid=(l+r)/2;
		LL ret=0;
		if (x<=mid)ret=query(tree[now].l,l,mid,x,y);
		if (y>mid)ret=ret+query(tree[now].r,mid+1,r,x,y);
		return ret;
	}
	
}sgt0,sgt1,Answer0,Answer1;

void add(int x){
	Answer0.change2(1,1,L,x,sgt0.query(1,1,L,x,x));
	Answer1.change2(1,1,L,x,sgt1.query(1,1,L,x,x));
}

int main(){
	fo(i,1,L)s0.insert(i),s1.insert(i);
	sgt0.init(1,L,INF);
	sgt1.init(1,L,INF);
	Answer0.init(1,L,0);
	Answer1.init(1,L,0);
	q=get();
	fo(cas,1,q){
		int ty=get(),l=get(),r=get()-1;
		if (ty==1){
			int v=get();
			if (v>0){
				sgt0.change1(1,1,L,l,r,v);
				Answer0.change1(1,1,L,l,r,v);
				for(set<int>::iterator h=s0.lower_bound(l);h!=s0.end()&&(*h)<=r;h=s0.lower_bound(l)){
					int x=*h;
					s0.erase(h);
					if (s1.find(x)==s1.end())add(x);
				}
			}
			else{
				sgt1.change1(1,1,L,l,r,-v);
				Answer1.change1(1,1,L,l,r,-v);
				for(set<int>::iterator h=s1.lower_bound(l);h!=s1.end()&&(*h)<=r;h=s1.lower_bound(l)){
					int x=*h;
					s1.erase(h);
					if (s0.find(x)==s0.end())add(x);
				}
			}
		}
		else printf("%lld\n",Answer0.query(1,1,L,l,r)+Answer1.query(1,1,L,l,r));
	}
	return 0;
}