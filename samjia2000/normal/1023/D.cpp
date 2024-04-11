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

const int N = 2e5+5;

int n,q;
int a[N];
int lef[N],rig[N];
struct node{
	int l,r,v;
}tree[N*2];
int tot;

void build(int &now,int l,int r){
	now=++tot;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

void down(int now){
	if (tree[now].v){
		tree[tree[now].l].v=tree[tree[now].r].v=tree[now].v;
		tree[now].v=0;
	}
}

void change(int now,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		tree[now].v=v;
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,y,v);
	if (y>mid)change(tree[now].r,mid+1,r,x,y,v);
}

int col[N];

void getcol(int now,int l,int r){
	if(l==r){
		col[l]=tree[now].v;
		return;
	}
	down(now);
	int mid=(l+r)/2;
	getcol(tree[now].l,l,mid);
	getcol(tree[now].r,mid+1,r);
}

int main(){
	n=get();q=get();
	fo(i,1,n)a[i]=get();
	bool all=1;
	fo(i,1,n)all&=(a[i]==0);
	if (all){
		printf("YES\n");
		fo(i,1,n)printf("%d ",q);
		putchar('\n');
		return 0;
	}
	bool isq=0;
	fo(i,1,n)isq|=(a[i]==q);
	if (!isq){
		fo(i,1,n)
		if (!a[i]){
			a[i]=q;
			isq=1;
			break;
		}
	}
	if (!isq)return printf("NO\n"),0;
	int lst=0;
	fo(i,1,n)
	if (!a[i]){
		if (i==n||a[i+1]!=0){
			int v=max(a[i+1],a[lst]);
			fo(x,lst+1,i)a[x]=v;
		}
	}
	else lst=i;
	fo(i,1,q)lef[i]=n+1,rig[i]=0;
	fo(i,1,n)lef[a[i]]=min(lef[a[i]],i);
	fo(i,1,n)rig[a[i]]=max(rig[a[i]],i);
	fo(i,1,q-1)if (lef[i]>rig[i])lef[i]=lef[q],rig[i]=rig[q];
	tot=0;
	int rt;
	build(rt,1,n);
	fo(i,1,q)change(1,1,n,lef[i],rig[i],i);
	getcol(1,1,n);
	bool ans=1;
	fo(i,1,n)ans&=(col[i]==a[i]);
	if (ans){
		printf("YES\n");
		fo(i,1,n)printf("%d ",col[i]);
		return 0;
	}
	else printf("NO\n");
	return 0;
}