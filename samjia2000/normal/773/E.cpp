#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int,int> pir;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

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

const int N = 5e5+5;
const int INF = 1e9;

int n;
int a[N];
struct node{
	int l,r;
	ui key;
	int val,tot;
	pir tr;
}tree[N];
int tot,rt;

pir operator *(pir a,pir b){
	int tmp=min(INF,a.fi+b.fi);
	return make_pair(tmp,min(a.se+b.fi,b.se));
}

void update(int x){
	tree[x].tot=tree[tree[x].l].tot+tree[tree[x].r].tot+1;
	tree[x].tr=make_pair(1,tree[x].val);
	if (tree[x].l)tree[x].tr=tree[tree[x].l].tr*tree[x].tr;
	if (tree[x].r)tree[x].tr=tree[x].tr*tree[tree[x].r].tr;
}

int merge(int x,int y){
	if (!x||!y)return x^y;
	if (tree[x].key<tree[y].key){
		tree[x].r=merge(tree[x].r,y);
		update(x);
		return x;
	}
	tree[y].l=merge(x,tree[y].l);
	update(y);
	return y;
}

pir split1(int now,int v){
	if (!now)return make_pair(0,0);
	if (tree[now].val<v){
		pir u=split1(tree[now].r,v);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split1(tree[now].l,v);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

pir split0(int now,int k){
	if (!k)return make_pair(0,now);
	if (k>=tree[now].tot)return make_pair(now,0);
	if (tree[tree[now].l].tot+1<=k){
		pir u=split0(tree[now].r,k-tree[tree[now].l].tot-1);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split0(tree[now].l,k);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

int getw(int now,int pre){
	if (!now)return pre+1;
	if (-(pre+tree[tree[now].l].tot+1)>=tree[now].val)return getw(tree[now].r,pre+tree[tree[now].l].tot+1);
	return getw(tree[now].l,pre);
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	rt=0;
	seed=20010419;
	fo(i,1,n){
		pir u=split1(rt,a[i]);
		tree[++tot].key=getrand();
		tree[tot].val=a[i];
		tree[tot].tr=make_pair(1,a[i]);
		tree[tot].tot=1;
		rt=merge(u.fi,merge(tot,u.se));
		int w=getw(rt,0);
		if (w>i){
			printf("%d\n",-i);
			continue;
		}
		u=split0(rt,w-1);
		pir v=tree[u.se].tr;
		printf("%d\n",min(-w+1+v.fi,v.se));
		rt=merge(u.fi,u.se);
	}
	return 0;
}