#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
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

const int N = 10010;

int a[N];
struct point{
	int l,r,tot;
}tree[N*20];
int tot,root[N],n,m;

void change(int &now,int qf,int l,int r,int x){
	now=++tot;
	tree[now]=tree[qf];
	tree[now].tot++;
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,tree[qf].l,l,mid,x);
	else change(tree[now].r,tree[qf].r,mid+1,r,x);
}

int getv(int rf,int lf,int l,int r,int x){
	if (r<=x)return tree[rf].tot-tree[lf].tot;
	int mid=(l+r)/2,ans=0;
	if (x>mid)ans=getv(tree[rf].r,tree[lf].r,mid+1,r,x);
	ans=ans+getv(tree[rf].l,tree[lf].l,l,mid,x);
	return ans;
}

int main(){
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)change(root[i],root[i-1],1,n,a[i]);
	fo(i,1,m){
		int l=get(),r=get(),x=get();
		if (x<l||x>r)printf("Yes\n");
		else{
			if (x-l+1==getv(root[r],root[l-1],1,n,a[x]))printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}