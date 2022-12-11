#include<bits/stdc++.h>

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

int n,k;
struct section{
	int l,r;
}s[N];
int key[N*2],m;
struct node{
	int len,l,r;
	int mx,mi,ad;
}tree[N*4];
int rt,tot;

int getw(int v){
	int l=1,r=m+1,ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (key[mid]>=v)r=mid-1,ret=mid;
		else l=mid+1;
	}
	return ret;
}

int val[N*2];

void build(int &now,int l,int r){
	now=++tot;
	tree[now].mx=1e9;
	tree[now].l=tree[now].r=tree[now].ad=0;
	tree[now].mi=-1e9;
	if (l==r){
		tree[now].len=key[l+1]-key[l];
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].len=tree[tree[now].l].len+tree[tree[now].r].len;
}

int Left,Right,sum;
LL all;
int st[N],ed[N];
struct addition{
	int x,v;
	addition(const int x_=0,const int v_=0){x=x_;v=v_;}
}ad[N*4];
int u;
int vis[N],tim;
int id[N];

void add(int x,int v){
	if (x<0||x>n)return;
	if (vis[x]<tim){
		vis[x]=tim;
		ad[id[x]=++u].x=x;
	}
	ad[id[x]].v+=v;
}

void down(int now){
	if (tree[now].ad){
		int x=tree[now].l;
		tree[x].mx=tree[x].mi=tree[x].ad=tree[now].ad;
		x=tree[now].r;
		tree[x].mx=tree[x].mi=tree[x].ad=tree[now].ad;
		tree[now].ad=0;
	}
}

void cover(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		if (tree[now].mx==tree[now].mi||l==r){
			add(tree[now].mx,-tree[now].len);
			add(v,tree[now].len);
			tree[now].ad=tree[now].mx=tree[now].mi=v;
			return;
		}
		down(now);
		int mid=(l+r)/2;
		cover(tree[now].l,l,mid,x,y,v);
		cover(tree[now].r,mid+1,r,x,y,v);
		tree[now].mx=max(tree[tree[now].l].mx,tree[tree[now].r].mx);
		tree[now].mi=min(tree[tree[now].l].mi,tree[tree[now].r].mi);
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if(x<=mid)cover(tree[now].l,l,mid,x,y,v);
	if(y>mid)cover(tree[now].r,mid+1,r,x,y,v);
	tree[now].mx=max(tree[tree[now].l].mx,tree[tree[now].r].mx);
	tree[now].mi=min(tree[tree[now].l].mi,tree[tree[now].r].mi);
}

pair<LL,LL> solve(int lim){
	fo(i,1,n)val[i]=0;
	pair<LL,LL>ret=make_pair(0,0);
	Left=1,Right=0,sum=0;
	all=0;
	fo(i,1,n){
		Right++;
		fo(t,st[i],ed[i]){
			int x=ad[t].x,v=ad[t].v;
			val[x]+=v;
			if (x>=Left)sum=sum+v;
			if (x<=Left)all=all+1ll*v*x;
		}
		while(Left<Right&&sum-val[Left]>=lim){
			sum-=val[Left++];
			all=all+1ll*val[Left]*Left;
		}
		if (sum>=lim){
			ret.first=ret.first+Left;
			ret.second=ret.second+all+1ll*(sum-val[Left])*Left;
		}
	}
	return ret;
}

int main(){
	n=get();k=get();
	fo(i,1,n){
		s[i].l=get(),s[i].r=get();
		key[++m]=s[i].l;
		key[++m]=s[i].r;
	}
	sort(key+1,key+1+m);
	int m_=1;
	fo(i,2,m)if (key[i]>key[i-1])key[++m_]=key[i];
	m=m_;
	m--;
	fo(i,1,n){
		s[i].l=getw(s[i].l);
		s[i].r=getw(s[i].r)-1;
	}
	rt=tot=0;
	build(rt,1,m);
	fo(i,1,n){
		st[i]=u+1;
		tim++;
		cover(1,1,m,s[i].l,s[i].r,i);
		ed[i]=u;
	}
	int l=1,r=1e9;
	LL ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		pair<LL,LL> u=solve(mid);
		if (u.first>=k){
			l=mid+1;
			ans=u.second-(u.first-k)*mid;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}