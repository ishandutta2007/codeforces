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
#define getw(x,v) (x+1+(v))/2
#define Trans(sss) ans_sum=ans_sum*2;if ((sss)==1)ans_sum=ans_sum-ans_tot

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

const int N = 2e5+5;

int n,m;
struct operate{
	int l,r;
}op[N];
struct addition{
	int x,id;
}ad[N*2];
int u;

bool cmp(addition a,addition b){return a.x<b.x;}

struct node{
	int l,r,tot;
	bool ad;
	LL sum;
}tree[N*4];
int rt[2],tot;

void build(int &now,int l,int r){
	now=++tot;
	tree[now].tot=r-l+1;
	tree[now].ad=0;
	if (l==r){tree[now].sum=l;return;}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].sum=tree[tree[now].l].sum+tree[tree[now].r].sum;
}

void change(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		tree[now].tot=tree[now].sum=0;
		tree[now].ad=1;
		return;
	}
	int mid=(l+r)/2;
	if (tree[now].ad){
		tree[tree[now].l].tot=tree[tree[now].l].sum=tree[tree[now].r].tot=tree[tree[now].r].sum=0;
		tree[tree[now].l].ad=tree[tree[now].r].ad=1;
		tree[now].ad=0;
	}
	if (x<=mid)change(tree[now].l,l,mid,x,y);
	if (y>mid)change(tree[now].r,mid+1,r,x,y);
	tree[now].sum=tree[tree[now].l].sum+tree[tree[now].r].sum;
	tree[now].tot=tree[tree[now].l].tot+tree[tree[now].r].tot;
}

LL ans_tot,ans_sum;

void query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		ans_tot=ans_tot+tree[now].tot;
		ans_sum=ans_sum+tree[now].sum;
		return;
	}
	if (tree[now].ad){
		tree[tree[now].l].tot=tree[tree[now].l].sum=tree[tree[now].r].tot=tree[tree[now].r].sum=0;
		tree[tree[now].l].ad=tree[tree[now].r].ad=1;
		tree[now].ad=0;
	}
	int mid=(l+r)/2;
	if (x<=mid)query(tree[now].l,l,mid,x,y);
	if (y>mid)query(tree[now].r,mid+1,r,x,y);
}

struct status{
	int x,id;
	status(const int x_=0,const int id_=0){x=x_;id=id_;}
	friend bool operator <(status a,status b){return a.x!=b.x?a.x<b.x:a.id<b.id;}
};
set<status>s[2];

int pre[N];

int main(){
	m=get();n=get();
	fo(i,1,m){
		op[i].l=get();op[i].r=get();
		ad[++u].x=op[i].l;
		ad[u].id=i;
		ad[++u].x=op[i].r+1;
		ad[u].id=i;
		pre[op[i].l]++;
		pre[op[i].r+1]--;
	}
	build(rt[0],1,n);
	build(rt[1],1,n);
	sort(ad+1,ad+1+u,cmp);
	int w=1;
	int lef=0;
	LL ans=0;
	fo(i,1,n){
		while(w<=u&&ad[w].x==i){
			int id=ad[w].id;
			if (op[id].l==i)s[i&1].insert(status(i,id));
			else{
				int l=op[id].l,r=op[id].r;
				s[l&1].erase(status(op[id].l,id));
				if ((op[id].r&1)==(op[id].l&1)){
					int p=(op[id].r&1)^1;
					if (l!=r)change(rt[p],1,n,getw(l,p),getw(r-1,p));
				}
				else{
					int p=(op[id].r&1);
					if (getw(l,p)>1)change(rt[p],1,n,1,getw(l,p)-1);
					p^=1;
					change(rt[p],1,n,1,getw(r-1,p));
				}
			}
			w++;
		}
		int p=i&1;
		if (s[p^1].begin()==s[p^1].end()){
			//p
			ans_tot=ans_sum=0;
			query(rt[p],1,n,1,getw(i,p));
			Trans(p);
			ans=ans+1ll*(i+1)*ans_tot-ans_sum;
			//p^1
			int w;
			if (s[p].begin()!=s[p].end()){
				w=(*s[p].begin()).x;
				w=getw(w,p^1)-1;
			}
			else w=getw(i-1,p^1);
			ans_tot=ans_sum=0;
			if (w)query(rt[p^1],1,n,1,w);
			Trans(p^1);
			ans=ans+1ll*(i+1)*ans_tot-ans_sum;
		}
		else{
			//p
			ans_tot=ans_sum=0;
			set<status>::iterator h=s[p^1].end();
			h--;
			int w=getw((*h).x,p);
			query(rt[p],1,n,w,getw(i,p));
			Trans(p);
			ans=ans+1ll*(i+1)*ans_tot-ans_sum;
			//p^1
			//None
		}
	}
	fo(i,1,n)pre[i]+=pre[i-1];
	int lst=0;
	fo(i,1,n)
	if (!pre[i]){
		ans_tot=i-lst;
		ans_sum=1ll*(lst+1+i)*(i-lst)/2;
		ans=ans-(1ll*(i+1)*ans_tot-ans_sum);
	}
	else lst=i;
	cout<<ans<<endl;
	return 0;
}