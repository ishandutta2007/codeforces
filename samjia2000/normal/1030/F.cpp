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
const int mo = 1e9+7;

int n,q;
LL a[N];
int w[N];
struct node{
	LL sumw,suma;
	int l,r;
}tree[N*2];
int rt,tot;
LL L,R;
int key;
LL sumw,suma;

void build(int &now,int l,int r){
	now=++tot;
	if (l==r){
		tree[now].sumw=w[l];
		tree[now].suma=1ll*w[l]*a[l]%mo;
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].sumw=tree[tree[now].l].sumw+tree[tree[now].r].sumw;
	tree[now].suma=(tree[tree[now].l].suma+tree[tree[now].r].suma)%mo;
}

void change(int now,int l,int r,int x,int w){
	if (l==r){
		tree[now].sumw=w;
		tree[now].suma=1ll*a[l]*w%mo;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,w);
	else change(tree[now].r,mid+1,r,x,w);
	tree[now].sumw=tree[tree[now].l].sumw+tree[tree[now].r].sumw;
	tree[now].suma=(tree[tree[now].l].suma+tree[tree[now].r].suma)%mo;
}

void getkey(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		if (L+tree[now].sumw*2-R<0){
			L=L+tree[now].sumw;
			R=R-tree[now].sumw;
			return;
		}
		if (l==r){key=l;return;}
		int mid=(l+r)/2;
		getkey(tree[now].l,l,mid,x,y);
		if (key)return;
		getkey(tree[now].r,mid+1,r,x,y);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid){
		getkey(tree[now].l,l,mid,x,y);
		if (key)return;
	}
	if (y>mid)getkey(tree[now].r,mid+1,r,x,y);
}

void getsum(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		sumw=sumw+tree[now].sumw;
		suma=(suma+tree[now].suma)%mo;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)getsum(tree[now].l,l,mid,x,y);
	if (y>mid)getsum(tree[now].r,mid+1,r,x,y);
}

int main(){
	n=get();q=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)a[i]-=i;
	fo(i,1,n)w[i]=get();
	build(rt,1,n);
	fo(cas,1,q){
		int x=get(),y=get();
		if (x<0){
			x=-x;
			int v=y;
			change(1,1,n,x,v);
		}
		else{
			int l=x,r=y;
			L=R=0;
			key=0;
			sumw=suma=0;
			getsum(1,1,n,l,r);
			R=sumw;
			getkey(1,1,n,l,r);
			sumw=suma=0;
			getsum(1,1,n,l,key);
			sumw%=mo;
			LL ans=(sumw*a[key]%mo-suma)%mo;
			sumw=suma=0;
			if (key<r)getsum(1,1,n,key+1,r);
			sumw%=mo;
			ans=(ans+suma-sumw*a[key]%mo)%mo;
			ans=(ans+mo)%mo;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}