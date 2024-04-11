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

const int N = 1e5+5;

int n,q;
db prob[N];
struct node{
	int l,r;
	db vl,vr;
}tree[N*2];
int rt,tot;

void update(int now){
	node &T=tree[now],&L=tree[tree[now].l],&R=tree[tree[now].r];
	T.vl=L.vl*R.vl/(1.0-(1.0-R.vl)*L.vr);
	T.vr=R.vr+(1.0-R.vr)*L.vr*R.vl/(1.0-(1.0-R.vl)*L.vr);
}

void build(int &now,int l,int r){
	now=++tot;
	if (l==r){
		tree[now].vl=prob[l];
		tree[now].vr=prob[l];
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	update(now);
}

void change(int now,int l,int r,int x){
	if(l==r){
		tree[now].vl=prob[l];
		tree[now].vr=prob[l];
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x);
	else change(tree[now].r,mid+1,r,x);
	update(now);
}

db ansl,ansr;

void query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		if (ansl<0)ansl=tree[now].vl,ansr=tree[now].vr;
		else{
			node L,&R=tree[now];
			L.vl=ansl,L.vr=ansr;
			ansl=L.vl*R.vl/(1.0-(1.0-R.vl)*L.vr);
			ansr=R.vr+(1.0-R.vr)*L.vr*R.vl/(1.0-(1.0-R.vl)*L.vr);
		}
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)query(tree[now].l,l,mid,x,y);
	if (y>mid)query(tree[now].r,mid+1,r,x,y);
}

int main(){
	n=get();q=get();
	fo(i,1,n){
		int x=get(),y=get();
		prob[i]=1.0*x/y;
	}
	build(rt,1,n);
	fo(cas,1,q){
		int ty=get();
		if (ty==1){
			int x=get(),a=get(),b=get();
			prob[x]=1.0*a/b;
			change(1,1,n,x);
		}
		else{
			int l=get(),r=get();
			ansl=ansr=-1;
			query(1,1,n,l,r);
			printf("%.9lf\n",ansl);
		}
	}
	return 0;
}