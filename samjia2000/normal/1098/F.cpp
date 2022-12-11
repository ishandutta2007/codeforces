#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

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

const int N = 4e5+5;
const int MAXN = 5e6;

int n,q;
char s[N];
struct QUERY{
	int l,r,id;
	QUERY(const int l_=0,const int r_=0,const int id_=0){l=l_;r=r_;id=id_;}
};
LL ans[N];
struct sam_node{
	int son[26];
	int fa,len;
}sam[N];
int tot,key[N];

int add(int now,int c){
	int x=++tot;
	sam[x].len=sam[now].len+1;
	for(;now!=-1&&!sam[now].son[c];now=sam[now].fa)sam[now].son[c]=x;
	if (now==-1)sam[x].fa=0;
	else{
		int y=sam[now].son[c];
		if (sam[y].len==sam[now].len+1)sam[x].fa=y;
		else{
			int tmp=++tot;
			sam[tmp]=sam[y];
			sam[tmp].len=sam[now].len+1;
			sam[y].fa=sam[x].fa=tmp;
			for(;now!=-1&&sam[now].son[c]==y;now=sam[now].fa)sam[now].son[c]=tmp;
		}
	}
	return x;
}

int lef[N],rig[N],fa[N];
int mx[N],siz[N],tp[N],be[N],m;
int dfn[N],k,R[N],d[N];
int rt[N],pt;
struct node{
	int l,r,tot;
	LL sum;
}tree[MAXN];

void add(int &now,int qf,int l,int r,int x){
	tree[now=++pt]=tree[qf];
	tree[now].sum+=x;
	tree[now].tot++;
	if (l==r)return;
	int mid=(l+r)/2;
	if(x<=mid)add(tree[now].l,tree[qf].l,l,mid,x);
	else add(tree[now].r,tree[qf].r,mid+1,r,x);
}

pair<LL,int> operator + (pair<LL,int> a,pair<LL,int> b){return make_pair(a.fi+b.fi,a.se+b.se);}

pair<LL,int> query(int now,int qf,int l,int r,int x,int y){
	if (x>y)return make_pair(0,0);
	if (x<=l&&r<=y)return make_pair(tree[now].sum-tree[qf].sum,tree[now].tot-tree[qf].tot);
	int mid=(l+r)/2;
	pair<LL,int>ret=make_pair(0,0);
	if (x<=mid)ret=query(tree[now].l,tree[qf].l,l,mid,x,y);
	if (y>mid)ret=ret+query(tree[now].r,tree[qf].r,mid+1,r,x,y);
	return ret;
}

void dfs1(int x){
	siz[x]=1;
	for(int y=lef[x];y;y=rig[y]){
		dfs1(y);
		siz[x]+=siz[y];
		if (!mx[x]|siz[y]>siz[mx[x]])mx[x]=y;
	}
}

void dfs2(int x){
	d[dfn[x]=++k]=x;
	if (!mx[x]){
		tp[be[x]=++m]=x;
		R[x]=k;
		return;
	}
	dfs2(mx[x]);
	tp[be[x]=be[mx[x]]]=x;
	for(int y=lef[x];y;y=rig[y])
		if(y!=mx[x])dfs2(y);
	R[x]=k;
}

void build(){
	int now=0;
	sam[0].fa=-1;
	fo(i,1,n)key[i]=now=add(now,s[i]-'a');
	fo(i,1,tot){
		fa[i]=sam[i].fa;
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	fo(i,1,tot)
	if (!fa[i]){
		dfs1(i);
		dfs2(i);
	}
	fo(i,1,k){
		int x=d[i];
		rt[i]=rt[i-1];
		if (x&&key[sam[x].len]==x)add(rt[i],rt[i],1,n,sam[x].len);
	}
}

struct Addition_Query{
	QUERY q;
	int nxt;
}qry[N*10];
int hq[N],qt;

void add_query(int x,QUERY a){qry[++qt].q=a;qry[qt].nxt=hq[x];hq[x]=qt;}

struct Addition_position{
	int x,nxt;
}pos[N*10];
int hp[N],ts;

void add_pos(int x,int y){pos[++ts].x=y;pos[ts].nxt=hp[x];hp[x]=ts;}

struct sgt_node{
	LL sum,ad1,ad0;
}sgt[N*2];
int vis[N*2],tim;

void update(int now){
	if (vis[now]<tim)vis[now]=tim,sgt[now].sum=sgt[now].ad1=sgt[now].ad0=0;
}

void add1(int now,int l,int r,int x,int v){
	update(now);
	sgt[now].sum=sgt[now].sum+v;
	if (l==r)return;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)add1(ls,l,mid,x,v);
	else add1(rs,mid+1,r,x,v);
}

LL query1(int now,int l,int r,int x,int y){
	update(now);
	if (x<=l&&r<=y)return sgt[now].sum;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	LL ret=0;
	if (x<=mid)ret=query1(ls,l,mid,x,y);
	if (y>mid)ret=ret+query1(rs,mid+1,r,x,y);
	return ret;
}

void add2(int now,int l,int r,int x,int y){
	update(now);
	if (x<=l&&r<=y){
		sgt[now].ad0=sgt[now].ad0+x;
		sgt[now].ad1=sgt[now].ad1-1;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)add2(ls,l,mid,x,y);
	if (y>mid)add2(rs,mid+1,r,x,y);
}

LL query2(int now,int l,int r,int x){
	update(now);
	LL ret=sgt[now].ad0+sgt[now].ad1*x;
	if (l==r)return ret;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	return ret+(x<=mid?query2(ls,l,mid,x):query2(rs,mid+1,r,x));
}

void solve(int st){
	tim++;
	for(int i=dfn[st],x=st;be[x]==be[st];x=d[++i]){
		for(int p=hq[x];p;p=qry[p].nxt){
			int l=qry[p].q.l,r=qry[p].q.r,id=qry[p].q.id;
			ans[id]=ans[id]+query1(1,1,n,l,r)+query2(1,1,n,l);
		}
		for(int p=hp[x];p;p=pos[p].nxt){
			int r=pos[p].x,l=r-sam[x].len+1;
			add1(1,1,n,r,sam[x].len);
			add2(1,1,n,l,r);
		}
	}
}

void getans(){
	fo(i,1,n){
		for(int x=key[i];x;x=fa[tp[be[x]]])add_pos(x,i);
	}
	fo(i,1,tot)if (tp[be[i]]==i)solve(i);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	reverse(s+1,s+1+n);
	build();
	q=get();
	fo(i,1,q){
		int l=get(),r=get();
		l=n-l+1,r=n-r+1;
		swap(l,r);
		int x=key[r];
		int len=r-l+1;
		for(;sam[fa[x]].len>=len;){
			if (sam[fa[tp[be[x]]]].len>=len)x=fa[tp[be[x]]];
			else{
				int l=dfn[tp[be[x]]],r=dfn[x];
				int w;
				while(l<=r){
					int mid=(l+r)/2;
					if (sam[d[mid]].len>=len)w=mid,r=mid-1;
					else l=mid+1;
				}
				x=d[w];
			}
		}
		pair<LL,int>u=query(rt[R[x]],rt[dfn[x]-1],1,n,l,r);
		ans[i]=u.fi-1ll*(l-1)*u.se;
		for(;x;){
			int y=tp[be[x]];
			int z=fa[y];
			if (z){
				int L=sam[z].len;
				pair<LL,int>u=make_pair(0,0),v=make_pair(0,0);
				if (dfn[z]<dfn[y])u=query(rt[dfn[y]-1],rt[dfn[z]-1],1,n,l,l+L-1),v=query(rt[dfn[y]-1],rt[dfn[z]-1],1,n,l+L,r);
				if (R[y]<R[z])u=u+query(rt[R[z]],rt[R[y]],1,n,l,l+L-1),v=v+query(rt[R[z]],rt[R[y]],1,n,l+L,r);
				ans[i]=ans[i]+1ll*v.se*L+u.fi-1ll*(l-1)*u.se;
			}
			add_query(x,QUERY(l,r,i));
			x=z;
		}
	}
	getans();
	fo(i,1,q)printf("%I64d\n",ans[i]);
	return 0;
}