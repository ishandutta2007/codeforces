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

const int N = 100005;
const int L = 1e5;

int n,m;
struct edge{
	int x,y,w;
}e[N];
int f[N];
struct node{
	int l,r,val;
}tree[N*20];
int rt[N],tot;
int vis[N],tim;

void change(int &now,int l,int r,int x,int v){
	if (!now){
		now=++tot;
		tree[now].l=tree[now].r=tree[now].val=0;
	}
	if (l==r){tree[now].val=max(tree[now].val,v);return;}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v);
	else change(tree[now].r,mid+1,r,x,v);
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
}

int getmax(int now,int l,int r,int x,int y){
	if (!now)return 0;
	if (x<=l&&r<=y)return tree[now].val;
	int mid=(l+r)/2,ret=0;
	if (x<=mid)ret=getmax(tree[now].l,l,mid,x,y);
	if (y>mid)ret=max(ret,getmax(tree[now].r,mid+1,r,x,y));
	return ret;
}

int main(){
	n=get();m=get();
	fo(i,1,m){e[i].x=get();e[i].y=get();e[i].w=get();}
	fo(i,1,m){
		f[i]=max(f[i],1);
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if (w)f[i]=max(f[i],getmax(rt[x],0,L,0,w-1)+1);
		change(rt[y],0,L,w,f[i]);
	}
	int ans=0;
	fo(i,1,m)ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}