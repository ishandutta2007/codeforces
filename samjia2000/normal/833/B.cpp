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
#define se second
#define fi first

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

const int N = 35010;
const int K = 55;

int f[N][K];
int n,k;
int a[N];
map<int,int>w;
int nxt[N],lst[N];
struct point{
	int val,ad;
}tree[K][N*2];
int ls[N*2],rs[N*2];
int tot;

void build(int &now,int l,int r){
	now=++tot;
	fo(i,1,k)tree[i][now].ad=0,tree[i][now].val=-1e+9;
	if (l==r)return;
	int mid=(l+r)/2;
	build(ls[now],l,mid);
	build(rs[now],mid+1,r);
}

void down(int t,int now){
	if (tree[t][now].ad!=0){
		tree[t][ls[now]].val+=tree[t][now].ad;
		tree[t][ls[now]].ad+=tree[t][now].ad;
		tree[t][rs[now]].val+=tree[t][now].ad;
		tree[t][rs[now]].ad+=tree[t][now].ad;
		tree[t][now].ad=0;
	}
}

void change(int t,int now,int l,int r,int x,int v){
	if (l==r){
		tree[t][now].val=v;
		return;
	}
	down(t,now);
	int mid=(l+r)/2;
	if (x<=mid)change(t,ls[now],l,mid,x,v);
	else change(t,rs[now],mid+1,r,x,v);
	tree[t][now].val=max(tree[t][ls[now]].val,tree[t][rs[now]].val);
}

void add(int t,int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tree[t][now].val=tree[t][now].val+v;
		tree[t][now].ad=tree[t][now].ad+v;
		return;
	}
	down(t,now);
	int mid=(l+r)/2;
	if (x<=mid)add(t,ls[now],l,mid,x,y,v);
	if (y>mid)add(t,rs[now],mid+1,r,x,y,v);
	tree[t][now].val=max(tree[t][ls[now]].val,tree[t][rs[now]].val);
}

int main(){
	n=get();k=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n){
		int x=a[i];
		if (w[x]){
			lst[i]=w[x];
			nxt[w[x]]=i;
		}
		w[x]=i;
	}
	map<int,int>::iterator h=w.begin();
	for(;h!=w.end();h++)nxt[(*h).se]=n+1;
	int rt;
	build(rt,1,n);
	int qt=0;
	f[0][0]=0;
	fo(i,1,k)f[0][i]=-1e+9;
	fo(i,1,n)fo(j,1,k)f[i][j]=-1e+9;
	fo(i,1,n){
		if (lst[i]){
			int x=lst[i];
			fo(j,1,k){
				change(j,1,1,n,x,-1e+9);
				add(j,1,1,n,1,x,-1);
			}
		}
		else qt++;
		fo(j,1,k)add(j,1,1,n,1,i,1);
		f[i][1]=qt;
		fo(j,2,min(i,k)){
			int v=f[i-1][j-1]+1;
			change(j,1,1,n,i,v);
		}
		fo(j,2,min(i,k))
			f[i][j]=tree[j][1].val;
	}
	printf("%d\n",f[n][k]);
	return 0;
}