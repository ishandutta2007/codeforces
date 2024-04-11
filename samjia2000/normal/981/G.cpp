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
const int mo = 998244353;

int n,q;
struct node1{
	int l,r,tot;
}tree1[N*80];
int rt1[N],tot1;
struct node2{
	LL ad1,ad2,sum;
	int l,r;
}tree2[N*2];
int tot2,rt2;

void build2(int &now,int l,int r){
	now=++tot2;
	tree2[now].sum=0;
	tree2[now].ad1=1;
	tree2[now].ad2=0;
	if (l==r)return;
	int mid=(l+r)/2;
	build2(tree2[now].l,l,mid);
	build2(tree2[now].r,mid+1,r);
}

void down(int now,int l,int r){
	int mid=(l+r)/2;
	int x=tree2[now].l;
	LL v1=tree2[now].ad1,v2=tree2[now].ad2;
	
	tree2[x].ad1=tree2[x].ad1*v1%mo;
	tree2[x].ad2=(tree2[x].ad2*v1+v2)%mo;
	tree2[x].sum=(tree2[x].sum*v1+1ll*v2*(mid-l+1))%mo;
	
	x=tree2[now].r;
	tree2[x].ad1=tree2[x].ad1*v1%mo;
	tree2[x].ad2=(tree2[x].ad2*v1+v2)%mo;
	tree2[x].sum=(tree2[x].sum*v1+1ll*v2*(r-mid))%mo;
	
	tree2[now].ad1=1,tree2[now].ad2=0;
}

void change2(int now,int l,int r,int x,int y,int v1,int v2){
	if (x<=l&&r<=y){
		tree2[now].ad1=tree2[now].ad1*v1%mo;
		tree2[now].ad2=(tree2[now].ad2*v1+v2)%mo;
		tree2[now].sum=(tree2[now].sum*v1+1ll*v2*(r-l+1))%mo;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)change2(tree2[now].l,l,mid,x,y,v1,v2);
	if (y>mid)change2(tree2[now].r,mid+1,r,x,y,v1,v2);
	tree2[now].sum=(tree2[tree2[now].l].sum+tree2[tree2[now].r].sum)%mo;
}

void change1(int &now,int l,int r,int x,int y){
	if (!now)now=++tot1;
	if (tree1[now].tot==r-l+1){change2(rt2,1,n,max(l,x),min(r,y),2,0);return;}
	if (x<=l&&r<=y){
		if (tree1[now].tot==0){
			tree1[now].tot=r-l+1;
			change2(rt2,1,n,l,r,1,1);
			return;
		}
		int mid=(l+r)/2;
		change1(tree1[now].l,l,mid,x,y);
		change1(tree1[now].r,mid+1,r,x,y);
		tree1[now].tot=tree1[tree1[now].l].tot+tree1[tree1[now].r].tot;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)change1(tree1[now].l,l,mid,x,y);
	if (y>mid)change1(tree1[now].r,mid+1,r,x,y);
	tree1[now].tot=tree1[tree1[now].l].tot+tree1[tree1[now].r].tot;
}

LL getsum2(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree2[now].sum;
	down(now,l,r);
	int mid=(l+r)/2;
	LL ret=0;
	if (x<=mid)ret=getsum2(tree2[now].l,l,mid,x,y);
	if (y>mid)ret=(ret+getsum2(tree2[now].r,mid+1,r,x,y))%mo;
	return ret;
}

int main(){
	n=get();q=get();
	build2(rt2,1,n);
	fo(cas,1,q){
		int ty=get();
		if (ty==1){
			int l=get(),r=get(),x=get();
			change1(rt1[x],1,n,l,r);
		}
		else{
			int l=get(),r=get();
			cout<<getsum2(rt2,1,n,l,r)<<endl;
		}
	}
	return 0;
}