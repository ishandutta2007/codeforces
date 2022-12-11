#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;

const int N = 100010;
const int mo = 1e+9+7;

LL add(LL x,LL y){
	return x+y>=mo?x+y-mo:x+y;
}
struct number{
	LL a,b;
	number(const LL a_=0,const LL b_=0){a=a_;b=b_;}
};
number operator *(number a,number b){return number((a.a*b.b%mo+a.b*b.a%mo+a.a*b.a%mo)%mo,(a.b*b.b%mo+a.a*b.a%mo)%mo);}
number operator +(number a,number b){return number(add(a.a,b.a),add(a.b,b.b));}
struct node{
	int l,r;
	number v,ad;
}tree[N*2];
int tot;
int n,m;
int a[N];

number getnumber(int tim){
	number ans=number(0,1);
	number v=number(1,0);
	for(;tim;tim/=2,v=v*v)
	if (tim&1)ans=ans*v;
	return ans;
}

number quickmi(number v,int tim){
	number ans=number(0,1);
	for(;tim;tim/=2,v=v*v)
	if (tim&1)ans=ans*v;
	return ans;
}

void build(int &now,int l,int r){
	now=++tot;
	if (l==r){
		tree[now].v=getnumber(a[l]);
		tree[now].ad=number(0,1);
		return ;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
	tree[now].ad=number(0,1);
}

void down(int now,int l,int r){
	int mid=(l+r)/2;
	int ls=tree[now].l,rs=tree[now].r;
	tree[ls].v=tree[ls].v*tree[now].ad;
	tree[rs].v=tree[rs].v*tree[now].ad;
	tree[ls].ad=tree[ls].ad*tree[now].ad;
	tree[rs].ad=tree[rs].ad*tree[now].ad;
	tree[now].ad=number(0,1);
}

void change(int now,int l,int r,int x,int y,number v){
	if (x<=l&&r<=y){
		tree[now].v=tree[now].v*v;
		tree[now].ad=tree[now].ad*v;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,y,v);
	if (y>mid)change(tree[now].r,mid+1,r,x,y,v);
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
}

number getans(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].v;
	down(now,l,r);
	int mid=(l+r)/2;
	number ans=number(0,0);
	if (x<=mid)ans=getans(tree[now].l,l,mid,x,y);
	if (y>mid)ans=ans+getans(tree[now].r,mid+1,r,x,y);
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%d",&a[i]);
	int rt;
	build(rt,1,n);
	fo(i,1,m){
		int ty,l,r;
		scanf("%d%d%d",&ty,&l,&r);
		if (ty==1){
			int x;
			scanf("%d",&x);
			change(1,1,n,l,r,getnumber(x));
		}
		else{
			number ans=getans(1,1,n,l,r);
			printf("%I64d\n",ans.a);
		}
	}
	return 0;
}