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

const int N = 1e5+5;
const LL INF = 1e18;

int n;
int a[N];
LL pre[N];
struct element{
	LL sum,tot;
	element(const LL sum_=0,const LL tot_=0){sum=sum_;tot=tot_;}
	friend element operator + (element a,element b){return element(a.sum+b.sum,a.tot+b.tot);}
	friend bool operator >(element a,element b){return a.sum!=b.sum?a.sum>b.sum:a.tot<b.tot;}
};
int R[N];
bool bz[N];
struct section{
	int l,r;
	section(const int l_=0,const int r_=0){l=l_;r=r_;}
}s[N];
LL mi[N][20],mx[N][20];

LL getmx(int l,int r){
	LL ret=-INF;
	if (l<1)ret=0,l++;
	if (l<=r){
		int t=log(r-l+1)/log(2);
		ret=max(ret,max(mx[l][t],mx[r-(1<<t)+1][t]));
	}
	return ret;
}

LL getmi(int l,int r){
	LL ret=INF;
	if (l<1)ret=0,l++;
	if (l<=r){
		int t=log(r-l+1)/log(2);
		ret=min(ret,min(mi[l][t],mi[r-(1<<t)+1][t]));
	}
	return ret;
}

element f[N];

struct node{
	LL sum;
	int tot,mx,l,r;
}tree[N*20];
int rt[N],tot;
LL key[N];
int num[N],rk[N];

void add(int &now,int qf,int l,int r,int x){
	tree[now=++tot]=tree[qf];
	tree[now].tot=tree[now].tot+1;
	tree[now].mx=max(tree[now].mx,num[x]);
	tree[now].sum=tree[now].sum+key[x];
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,tree[qf].l,l,mid,x);
	else add(tree[now].r,tree[qf].r,mid+1,r,x);
}

int Mx,Tot;
LL Sum;

void query(int now,int l,int r,LL v){
	if (!now||key[r]<=v)return;
	if (key[l]>v){
		Mx=max(Mx,tree[now].mx);
		Tot+=tree[now].tot;
		Sum+=tree[now].sum;
		return;
	}
	if(l==r)return;
	int mid=(l+r)/2;
	if (v<key[mid])query(tree[now].l,l,mid,v);
	query(tree[now].r,mid+1,r,v);
}

element solve(LL d){
	element ret=element();
	fo(i,1,n)R[i]=0;
	fd(i,n,1){
		Mx=Tot=Sum=0;
		query(rt[i],1,n,pre[i-1]-d);
		R[i]=Mx;
		ret=ret+element(Sum-(pre[i-1]-d)*Tot,Tot);
	}
	fo(i,1,n)bz[i]=0;
	int w=0;
	fo(i,1,n)
	if (R[i]>w){
		w=max(w,i-1);
		for(;w<R[i];)bz[++w]=1;
	}
	int k=0;
	if (!bz[1])s[++k]=section(1,0);
	fo(i,1,n)
	if (bz[i]){
		if (i==1||!bz[i-1])s[++k]=section(i,0);
		if (i==n||!bz[i+1])s[k].r=i;
	}
	else
		if (i>1&&!bz[i-1])s[++k]=section(i+1,i);
	if (!bz[n])s[++k]=section(n+1,n);
	if (k==1)return ret;
	element p=element(-INF,0);
	fo(i,1,k){
		if (i==1)f[i]=element(0,0);
		else f[i]=p+element(getmx(s[i].l-1,s[i].r)+d,1);
		element t=f[i]+element(-getmi(s[i].l-1,s[i].r),0);
		if (t>p)p=t;
	}
	return ret+f[k];
}

bool cmp(int x,int y){return pre[x]<pre[y];}

int main(){
	n=get();
	LL K;
	cin>>K;
	fo(i,1,n)a[num[i]=i]=get();
	fo(i,1,n)pre[i]=pre[i-1]+a[i];
	sort(num+1,num+1+n,cmp);
	fo(i,1,n)rk[num[i]]=i,key[i]=pre[num[i]];
	fd(i,n,1)add(rt[i],rt[i+1],1,n,rk[i]);
	fo(i,1,n)mi[i][0]=mx[i][0]=pre[i];
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1){
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	LL l=-1e15,r=1e15;
	element ans;
	LL d;
	//element u=solve(7);
	while(l<=r){
		LL mid=(l+r)/2;
		element u=solve(mid);
		if (u.tot<=K)l=mid+1,ans=u,d=mid;
		else r=mid-1;
	}
	LL Ans=ans.sum-d*K;
	cout<<Ans<<endl;
	return 0;
}