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

const int N = 2e5+5;
const int L = 12;

LL quickmi(LL x,LL tim,LL mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
		if (tim&1)ret=ret*x%mo;
	return ret;
}

int n,q,mod,phi;
int a[N];
struct prime_divisor{
	int x,tim,v;
	LL mul;
}pri[L];
int k;
int res[N][L];
struct node{
	LL val[L];
	LL res[L],mul;
}tree[N];

void build(int now,int l,int r){
	tree[now].mul=1;
	if (l==r){
		fo(i,1,k)tree[now].val[i]=a[l]%pri[i].v;
		fo(i,0,k)tree[now].res[i]=res[a[l]][i];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	fo(i,1,k)tree[now].val[i]=(tree[ls].val[i]+tree[rs].val[i])%pri[i].v;
	tree[now].res[0]=1;
	fo(i,1,k)tree[i].res[i]=0;
}

void prepare(){
	{
		int s=mod;
		int u=sqrt(s);
		fo(i,2,u)
		if (s%i==0){
			int ps=s;
			pri[++k].x=i;
			for(;s%i==0;s/=i,pri[k].tim++);
			pri[k].v=ps/s;
		}
		if (s>1){
			pri[++k].x=s;
			pri[k].tim=1;
			pri[k].v=s;
		}
		fo(i,1,k){
			LL x=mod/pri[i].v;
			pri[i].mul=x*quickmi(x,pri[i].v/pri[i].x*(pri[i].x-1)-1,pri[i].v)%mod;
		}
		phi=1;
		fo(i,1,k)phi=phi*pri[i].v/pri[i].x*(pri[i].x-1);
	}
	fo(i,1,1e5)res[i][0]=i;
	fo(i,1,k){
		int x=pri[i].x;
		for(LL p=x;p<=1e5;p*=x)
			fo(t,1,1e5/p){
				int y=t*p;
				res[y][0]/=x;
				res[y][i]++;
			}
	}
	build(1,1,n);
}

void update(int now,int ls,int rs){
	fo(i,1,k)tree[now].val[i]=(tree[ls].val[i]+tree[rs].val[i])%pri[i].v;
}

void down(int now,int ls,int rs){
	tree[ls].mul=tree[ls].mul*tree[now].mul%mod;
	tree[rs].mul=tree[rs].mul*tree[now].mul%mod;
	tree[ls].res[0]=tree[ls].res[0]*tree[now].res[0]%mod;
	tree[rs].res[0]=tree[rs].res[0]*tree[now].res[0]%mod;
	tree[now].res[0]=1;
	fo(i,1,k){
		tree[ls].res[i]=tree[ls].res[i]+tree[now].res[i];
		tree[rs].res[i]=tree[rs].res[i]+tree[now].res[i];
		tree[now].res[i]=0;
		tree[ls].val[i]=tree[ls].val[i]*tree[now].mul%pri[i].v;
		tree[rs].val[i]=tree[rs].val[i]*tree[now].mul%pri[i].v;
	}
	tree[now].mul=1;
}

void change(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		fo(i,1,k)tree[now].val[i]=tree[now].val[i]*v%pri[i].v;
		tree[now].mul=tree[now].mul*v%mod;
		tree[now].res[0]=tree[now].res[0]*res[v][0]%mod;
		fo(i,1,k)tree[now].res[i]=tree[now].res[i]+res[v][i];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	down(now,ls,rs);
	if (x<=mid)change(ls,l,mid,x,y,v);
	if (y>mid)change(rs,mid+1,r,x,y,v);
	update(now,ls,rs);
}

void mdf(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].res[0]=tree[now].res[0]*quickmi(res[v][0],phi-1,mod)%mod;
		fo(i,1,k)tree[now].res[i]=tree[now].res[i]-res[v][i];
		LL ret=tree[now].res[0];
		fo(i,1,k)ret=ret*quickmi(pri[i].x,tree[now].res[i],mod)%mod;
		fo(i,1,k)tree[now].val[i]=ret%pri[i].v;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	down(now,ls,rs);
	if (x<=mid)mdf(ls,l,mid,x,v);
	else mdf(rs,mid+1,r,x,v);
	update(now,ls,rs);
}

LL ans[L];

void query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		fo(i,1,k)ans[i]=(ans[i]+tree[now].val[i])%mod;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	down(now,ls,rs);
	if (x<=mid)query(ls,l,mid,x,y);
	if (y>mid)query(rs,mid+1,r,x,y);
}

LL solve(int l,int r){
	fo(i,1,k)ans[i]=0;
	query(1,1,n,l,r);
	LL ret=0;
	fo(i,1,k)ret=(ret+ans[i]*pri[i].mul)%mod;
	return ret;
}

int main(){
	n=get();mod=get();
	fo(i,1,n)a[i]=get();
	prepare();
	q=get();
	fo(cas,1,q){
		int op=get();
		if (op==1){
			int l=get(),r=get(),x=get();
			change(1,1,n,l,r,x);
		}
		if (op==2){
			int x=get(),v=get();
			mdf(1,1,n,x,v);
		}
		if (op==3){
			int l=get(),r=get();
			printf("%I64d\n",solve(l,r));
		}
	}
	return 0;
}