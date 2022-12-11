#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 200010;

int sa[N],w[N],s[N],r[N],rank[N],height[N],rmq[N][20],y[N];
int n,q;
int h[N];
struct point{
	int l,r,tot;
}tree[N*20];
int tot,root[N],hf;

int get(){
	char ch;
	int s=0;
	while(ch=getchar(),ch<'0'||ch>'9');
	s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

bool cmp(int x,int y){
	return r[x]<r[y];
}

void getsa(){
	n<<=1;
	fo(i,1,n)sa[i]=i,r[i]=s[i];
	sort(sa+1,sa+1+n,cmp);
	int k=0;
	fo(i,1,n){
		if (i==1||s[sa[i]]>s[sa[i-1]])k++;
		r[sa[i]]=k;
	}
	int j=1;
	while(k<n){
		int tt=0;
		fo(i,n-j+1,n)y[++tt]=i;
		fo(i,1,n)
		if (sa[i]>j)y[++tt]=sa[i]-j;
		fo(i,1,n)w[i]=0;
		fo(i,1,n)w[r[y[i]]]++;
		fo(i,1,n)w[i]+=w[i-1];
		fd(i,n,1)sa[w[r[y[i]]]--]=y[i];
		fo(i,1,n)y[i]=r[i];
		r[sa[1]]=k=1;
		fo(i,2,n){
			if (y[sa[i]]>y[sa[i-1]]||(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]>y[sa[i-1]+j]))k++;
			r[sa[i]]=k;
		}
		j<<=1;
	}
}

void getheight(){
	fo(i,1,n)rank[sa[i]]=i;
	int j=0;
	fo(i,1,n){
		j=max(j-1,0);
		int x=sa[rank[i]-1];
		while(x+j<=n&&i+j<=n&&s[x+j]==s[i+j])j++;
		height[rank[i]]=j;
	}
}

void getrmq(){
	fo(i,1,n)rmq[i][0]=height[i];
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1)
		rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

void insert(int qf,int &now,int l,int r,int w){
	tree[now=++tot]=tree[qf];
	tree[now].tot++;
	if(l==r)return;
	int mid=(l+r)/2;
	if (w<=mid)insert(tree[qf].l,tree[now].l,l,mid,w);
	else insert(tree[qf].r,tree[now].r,mid+1,r,w);
}

void buildtree(){
	hf=n/2;
	fo(i,1,n){
		if (sa[i]<=hf)root[i]=root[i-1];
		else{
			int w=sa[i]-hf-1;
			if (w)insert(root[i-1],root[i],1,hf,w);
		}
	}
}

int gettot(int ls,int rs,int l,int r,int x,int y){
	if (l>=x&&r<=y)return tree[rs].tot-tree[ls].tot;
	int mid=(l+r)/2,ans=0;
	if (x<=mid)ans+=gettot(tree[ls].l,tree[rs].l,l,mid,x,y);
	if (y>mid)ans+=gettot(tree[ls].r,tree[rs].r,mid+1,r,x,y);
	return ans;
}

int getv(int l,int r){
	int t=log(r-l+1)/log(2);
	return min(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int getans(int x,int len){
	int l=1,r=rank[x]-1,w1=rank[x],w2=rank[x];
	while(l<=r){
		int mid=(l+r)/2;
		if (getv(mid+1,rank[x])<len)l=mid+1;
		else {
			w1=mid;
			r=mid-1;
		}
	}
	l=rank[x]+1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if (getv(rank[x]+1,mid)<len)r=mid-1;
		else{
			w2=mid;
			l=mid+1;
		}
	}
	int ans=0;
	if (x>len+2)ans+=gettot(root[w1-1],root[w2],1,hf,1,x-2-len);
	if (x+len<=hf)ans+=gettot(root[w1-1],root[w2],1,hf,x+len,hf);
	return ans;
}

int main(){
	n=get();
	fo(i,1,n)h[i]=get();
	fo(i,1,n)s[i]=h[i]-h[i-1];
	fo(i,1,n)s[n+i]=h[i-1]-h[i];
	getsa();
	getheight();
	getrmq();
	buildtree();
	q=get();
	fo(i,1,q){
		int x=get(),y=get();
		int len=y-x;
		if (len>0)printf("%d\n",getans(x+1,len));
		else printf("%d\n",hf-1);
	}
	return 0;
}