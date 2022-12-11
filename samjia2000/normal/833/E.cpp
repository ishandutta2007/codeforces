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
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int,int> pir;

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

int n,C;
struct segment{
	int l,r,c;
}seg[N];
int m;
struct request{
	int k,id;
}qry[N];
int ans[N];
struct addition{
	int x,id;
	addition(const int x_=0,const int id_=0){x=x_;id=id_;}
}ad[N*2];
int u;
int siz[N*2];
int key[N*2],k;
set<int>ext;

bool cmp(addition a,addition b){return a.x<b.x;}

pir be[N*2];

struct section{
	int lef,rig;
}sec[N];

struct node{
	int l,r,val,ad;
}tree[N*4];
int rt,tot;
int kth[N*2],s;
map<int,int>id[N];

void build(int &now,int l,int r){
	now=++tot;
	if (l==r){
		tree[now].val=-INF;
		int w=kth[l];
		if (seg[be[w].fi].c+seg[be[w].se].c<=C)tree[now].val=0;
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
}

int val[N],nowv;
int ept;

int kt[N],num[N],Ri[N];
struct node2{
	int l,r,val;
}tree2[N*2];
bool cmp1(int x,int y){return seg[x].c<seg[y].c;}

void prepare(){
	u=0;
	fo(i,1,n){
		ad[++u]=addition(seg[i].l,i);
		ad[++u]=addition(seg[i].r,i);
		num[i]=i;
	}
	sort(num+1,num+1+n,cmp1);
	fo(i,1,n)kt[num[i]]=i;
	int w=n;
	fo(i,1,n){
		int x=num[i];
		while(w&&seg[x].c+seg[num[w]].c>C)w--;
		Ri[x]=w;
	}
	fo(i,1,n)sec[i].lef=INF,sec[i].rig=0;
	u++;
	ad[u]=addition(0,0);
	sort(ad+1,ad+1+u,cmp);
	int lst=0,cnt=0;
	ext.clear();
	s=0;
	fo(i,1,u)
	if (i==u||ad[i].x!=ad[i+1].x){
		key[++k]=ad[i].x;
		fo(j,lst+1,i)
		if(ad[j].id){
			if (seg[ad[j].id].l==ad[i].x)ext.insert(ad[j].id),cnt++;
			else ext.erase(ad[j].id),cnt--;
		}
		siz[k]=cnt;
		if (cnt==1)be[k].fi=(*ext.begin());
		if (cnt==2){
			int x=be[k].fi=(*ext.begin());
			set<int>::iterator h=ext.begin();
			h++;
			x=be[k].se=*h;
			if (be[k].fi>be[k].se)swap(be[k].fi,be[k].se);
			if (!s||be[k].fi!=be[kth[s]].fi||be[k].se!=be[kth[s]].se){
				kth[++s]=k;
				id[be[k].fi][be[k].se]=s;
				sec[be[k].fi].lef=min(sec[be[k].fi].lef,s);
				sec[be[k].fi].rig=max(sec[be[k].fi].rig,s);
				sec[be[k].se].lef=min(sec[be[k].se].lef,s);
				sec[be[k].se].rig=max(sec[be[k].se].rig,s);
			}
		}
		lst=i;
	}
	nowv=0;
	fo(i,1,n)
	if (seg[i].c>C)val[i]=-INF;else val[i]=0;
	if (s)build(rt,1,s);
	key[k+1]=INF*2+5;
	ept=0;
}

int getw(int x){
	int l=1,r=k,ret=k;
	while(l<=r){
		int mid=(l+r)/2;
		if (key[mid+1]>x)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}

void down(int now){
	if (tree[now].ad!=0){
		int w=tree[now].l;
		tree[w].ad+=tree[now].ad;
		tree[w].val+=tree[now].ad;
		w=tree[now].r;
		tree[w].ad+=tree[now].ad;
		tree[w].val+=tree[now].ad;
		tree[now].ad=0;
	}
}

void change(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tree[now].ad=tree[now].ad+v;
		tree[now].val=tree[now].val+v;
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,y,v);
	if (y>mid)change(tree[now].r,mid+1,r,x,y,v);
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
}

int query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].val;
	down(now);
	int mid=(l+r)/2;
	int ret=-INF;
	if (x<=mid)ret=query(tree[now].l,l,mid,x,y);
	if (y>mid)ret=max(ret,query(tree[now].r,mid+1,r,x,y));
	return ret;
}

void change2(int now,int l,int r,int x,int v){
	if (l==r){
		tree2[now].val=v;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)change2(ls,l,mid,x,v);
	else change2(rs,mid+1,r,x,v);
	tree2[now].val=max(tree2[ls].val,tree2[rs].val);
}

int query2(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree2[now].val;
	int mid=(l+r)/2;	
	int ls=now+1,rs=now+(mid-l+1)*2;
	int ret=-INF;
	if (x<=mid)ret=query2(ls,l,mid,x,y);
	if (y>mid)ret=max(ret,query2(rs,mid+1,r,x,y));
	return ret;
}

bool cmp2(request a,request b){return a.k<b.k;}

void solve(){
	sort(qry+1,qry+1+m,cmp2);
	int w=1;
	fo(i,1,k){
		if (siz[i]>2)continue;
		int Len=key[i+1]-key[i];
		if (siz[i]==0){
			while(w<=m&&qry[w].k-nowv<=Len){
				ans[qry[w].id]=key[i]+qry[w].k-nowv;
				w++;
			}
			ept+=Len;
			nowv=nowv+Len;
		}
		if (siz[i]==1){
			int x=be[i].fi;
			int mx=val[x];
			if (Ri[x]){
				if (Ri[x]>=kt[x]){
					if (kt[x]>1)mx=max(mx,query2(1,1,n,1,kt[x]-1)+val[x]);
					if (kt[x]<Ri[x])mx=max(mx,query2(1,1,n,kt[x]+1,Ri[x])+val[x]);
				}
				else mx=max(mx,query2(1,1,n,1,Ri[x])+val[x]);
			}
			val[x]+=Len;
			change2(1,1,n,kt[x],val[x]);
			if (sec[x].lef<=sec[x].rig){
				mx=max(mx,query(rt,1,s,sec[x].lef,sec[x].rig));
				change(rt,1,s,sec[x].lef,sec[x].rig,Len);
			}
			mx=mx+ept;
			while(w<=m&&qry[w].k<=(LL)mx+Len){
				ans[qry[w].id]=key[i]+qry[w].k-mx;
				w++;
			}
			nowv=max(nowv,mx+Len);
		}
		if (siz[i]==2){
			int x=be[i].fi,y=be[i].se;
			int mx=ept+query(rt,1,s,id[x][y],id[x][y]);
			change(rt,1,s,id[x][y],id[x][y],Len);
			while(w<=m&&qry[w].k<=(LL)mx+Len){
				ans[qry[w].id]=key[i]+qry[w].k-mx;
				w++;
			}
			nowv=max(nowv,mx+Len);
		}
	}
}

int main(){
	n=get();C=get();
	fo(i,1,n){
		seg[i].l=get();seg[i].r=get();seg[i].c=get();
	}
	m=get();
	fo(i,1,m){
		qry[i].k=get();
		qry[i].id=i;
	}
	prepare();
	solve();
	fo(i,1,m)printf("%d\n",ans[i]);
	return 0;
}