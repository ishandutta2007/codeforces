#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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
const LL INF = 1e16;

int n;
LL C;
int s[N*2];
LL pre1[N],pre0[N];
struct node{
	int l,r;
	LL val0,val1;
}tree[N*2];
int rt,tot;
LL f[N];
int fff;

void build(int &now,int l,int r){
	now=++tot;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

LL maxll(LL x,LL y){return x>y?x:y;}

void change(int now,int l,int r,int x,LL v0,LL v1){
	if (l==r){
		tree[now].val0=v0;
		tree[now].val1=v1;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v0,v1);
	else change(tree[now].r,mid+1,r,x,v0,v1);
	tree[now].val0=maxll(tree[tree[now].l].val0,tree[tree[now].r].val0);
	tree[now].val1=maxll(tree[tree[now].l].val1,tree[tree[now].r].val1);
}

LL query0(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].val0;
	int mid=(l+r)/2;
	LL ret=-INF;
	if (x<=mid)ret=query0(tree[now].l,l,mid,x,y);
	if (y>mid)ret=maxll(ret,query0(tree[now].r,mid+1,r,x,y));
	return ret;
}

LL query1(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].val1;
	int mid=(l+r)/2;
	LL ret=-INF;
	if (x<=mid)ret=query1(tree[now].l,l,mid,x,y);
	if (y>mid)ret=maxll(ret,query1(tree[now].r,mid+1,r,x,y));
	return ret;
}


int main(){
	n=get();
	cin>>C;
	fo(i,1,n*2-1){
		s[i]=get();
		if (s[i]>C)s[i]=C;
	}
	fo(i,1,n)pre1[i]=pre1[i-1]+s[i*2]+s[i*2-1];
	fo(i,1,n)pre0[i]=pre1[i-1]+s[i*2-1];
	build(rt,1,n);
	int w=1;
	fo(i,1,n){
		f[i]=pre0[i];
		if (f[i]>C)f[i]=C;
		while(w<=n&&pre0[i]-pre1[w-1]>C)w++;
		if (max(1,w-1)<=i-1)f[i]=maxll(f[i],query1(1,1,n,max(1,w-1),i-1)+pre0[i]);
		if (w-2>0)f[i]=maxll(f[i],query0(1,1,n,1,w-2)+C);
		change(1,1,n,i,f[i],f[i]-pre1[i]);
	}
	cout<<f[n]<<endl;
	return 0;
}