#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

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

const int N = 3e5+5;
const int INF = 1e9;

int n,m;
struct operate{
	int ty,l,r,x,v;
}op[N];
struct addition{
	int x,id;
}ad[N*2];
int u;
int fir[N];
struct node{
	int val,l,r;
}tree[N*2];
int rt,tot;
int val[N];

void build(int &now,int l,int r){
	tree[now=++tot].val=INF+5;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

bool cmp(addition a,addition b){return a.x<b.x;}

void change(int now,int l,int r,int x,int v){
	if (l==r){tree[now].val=v;return;}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v);
	else change(tree[now].r,mid+1,r,x,v);
	tree[now].val=min(tree[tree[now].l].val, tree[tree[now].r].val);
}

int getval(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].val;
	int mid=(l+r)/2,ret=INF;
	if (x<=mid)ret=getval(tree[now].l,l,mid,x,y);
	if (y>mid)ret=min(ret,getval(tree[now].r,mid+1,r,x,y));
	return ret;
}

set<int>ext;

bool locked[N];

int main(){
	n=get();m=get();
	bool inf=0;
	fo(i,1,m){
		op[i].ty=get();
		if (op[i].ty==1){
			op[i].l=get();op[i].r=get();op[i].v=get();
			if (op[i].v==INF)inf=1;
		}
		else{
			op[i].x=get();op[i].v=get();
			if (!fir[op[i].x])fir[op[i].x]=i;
		}
	}
	build(rt,1,m);
	fo(i,1,m)
	if (op[i].ty==1){
		ad[++u].x=op[i].l;
		ad[u].id=i;
		ad[++u].x=op[i].r+1;
		ad[u].id=i;
	}
	sort(ad+1,ad+1+u,cmp);
	int w=1;
	fo(i,1,n){
		while(w<=u&&ad[w].x==i){
			int id=ad[w].id;
			if (op[id].l==i)change(1,1,m,id,op[id].v);
			else change(1,1,m,id,INF+5);
			w++;
		}
		if (fir[i])val[i]=getval(1,1,m,1,fir[i]);
		else val[i]=tree[1].val;
	}
	bool can=1;
	tot=0;
	build(rt,1,n);
	fo(i,1,n)change(1,1,n,i,-val[i]);
	fo(i,1,m)
	if (op[i].ty==1){
		int tmp=-getval(1,1,n,op[i].l,op[i].r);
		can&=(tmp==op[i].v);
	}
	else change(1,1,n,op[i].x,-op[i].v);
	if (!can)return printf("NO\n"),0;
	ext.clear();
	int cnt=0,res=0;
	bool pl=0;
	fo(i,1,n)
	if (val[i]<INF){
		if (ext.find(val[i])!=ext.end()){
			int v=1;
			for(;v*2-1<=val[i];v=v*2);
			val[i]=v-1;
		}
		else ext.insert(val[i]),locked[i]=1;
		res=res|val[i];
	}
	else{
		if (inf&&!pl&&val[i]==INF)locked[i]=1,res=res|INF,cnt--,pl=1;
		cnt++;
		val[i]=INF;
	}
	if (cnt){
		if (cnt==1){
			int v=INF,tv=INF|res;
			fo(x,0,30)
			if ((INF&(1<<x))>0){
				int tmp=res|(INF^(1<<x)|((1<<x)-1));
				if (tmp>tv){
					v=(INF^(1<<x)|((1<<x)-1));
					tv=tmp;
				}
			}
			fo(i,1,n)
			if(!locked[i]&&val[i]==INF)val[i]=v;
		}
		else{
			int pc=0;
			fo(i,1,n)
			if (!locked[i]&&val[i]==INF){
				if (!pc)val[i]=805306367;
				else val[i]=536870911;
				pc++;
			}
		}
	}
	printf("YES\n");
	fo(i,1,n)printf("%d ",val[i]);putchar('\n');
	return 0;
}