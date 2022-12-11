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
const int T = 30;

int dfn[T][N],d[T][N],k;
int num[N];
int n;
int a[N],to[N];
int fa[N],lef[N],rig[N];
int fir[N],dep[N],u;
int rmq[N*2][20];
int Dfn[N],D[N];

void dfs1(int x){
	D[Dfn[x]=dfn[T-1][x]]=x;
	rmq[fir[x]=++u][0]=x;
	for(int y=lef[x];y;y=rig[y]){
		dep[y]=dep[x]+1;
		dfs1(y);
		rmq[++u][0]=x;
	}
}

int lg[N*2];

void getrmq(){
	fo(j,1,log(u)/log(2))
		fo(i,1,u-(1<<j)+1)
		rmq[i][j]=dep[rmq[i][j-1]]<dep[rmq[i+(1<<(j-1))][j-1]]?rmq[i][j-1]:rmq[i+(1<<(j-1))][j-1];
	fo(i,1,u)lg[i]=log(i)/log(2);
}

int lca(int x,int y){
	x=fir[x],y=fir[y];
	if (x>y)swap(x,y);
	int t=lg[y-x+1];
	return dep[rmq[x][t]]<dep[rmq[y-(1<<t)+1][t]]?rmq[x][t]:rmq[y-(1<<t)+1][t];
}

void dfs(int x,int t){
	d[t][dfn[t][x]=++k]=x;
	for(int y=lef[x];y;y=rig[y])dfs(y,t);
}

void getdfn(int t){
	k=0;
	random_shuffle(num+1,num+1+n);
	fo(i,1,n)lef[i]=rig[i]=0;
	fo(i,1,n){
		int x=num[i];
		if (fa[x]){
			rig[x]=lef[fa[x]];
			lef[fa[x]]=x;
		}
	}
	dfs(1,t);
}

struct node{
	int a[T];
	int tp;
	
	int & operator [](int x){return a[x];}
}sgt[N*2];

void build(int now,int l,int r){
	if (l==r){
		int x=to[l];
		fo(i,0,T-1)sgt[now][i]=dfn[i][x];
		sgt[now].tp=Dfn[x];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	fo(i,0,T-1)sgt[now][i]=max(sgt[ls][i],sgt[rs][i]);
	sgt[now].tp=min(sgt[ls].tp,sgt[rs].tp);
}

void change(int now,int l,int r,int x){
	if (l==r){
		int w=to[l];
		fo(i,0,T-1)sgt[now][i]=dfn[i][w];
		sgt[now].tp=Dfn[w];
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)change(ls,l,mid,x);
	else change(rs,mid+1,r,x);
	fo(i,0,T-1)sgt[now][i]=max(sgt[ls][i],sgt[rs][i]);
	sgt[now].tp=min(sgt[ls].tp,sgt[rs].tp);	
}

int tp;
int key[T];

int getans(int now,int l,int r){
	int tp_=min(tp,sgt[now].tp);
	int fi=0,se=0;
	fo(i,0,T-1){
		int x=d[i][max(key[i],sgt[now][i])];
		if (x==fi||x==se)continue;
		if (!fi)fi=x;
		else{
			if (!se)se=x;
			else {fi=-1;break;}
		}
	}
	if (fi!=-1){
		if (!se||(se&&dep[lca(fi,se)]<=dep[D[tp_]])){
			tp=tp_;
			fo(i,0,T-1)key[i]=max(key[i],sgt[now][i]);
			return r;
		}
	}
	if (l==r)return l-1;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	int ret=getans(ls,l,mid);
	if (ret==mid)return getans(rs,mid+1,r);
	return ret;
}

int main(){
	srand(247878789);
	n=get();
	fo(i,1,n)to[a[i]=get()+1]=i;
	fo(i,2,n)fa[i]=get();
	fo(i,1,n)num[i]=i;
	fo(t,0,T-1)getdfn(t);
	dfs1(dep[1]=1);
	getrmq();
	build(1,1,n);
	for(int _=get();_;_--){
		int ty=get();
		if (ty==1){
			int x=get(),y=get();
			swap(a[x],a[y]);
			to[a[x]]=x;
			to[a[y]]=y;
			change(1,1,n,a[x]);
			change(1,1,n,a[y]);
		}
		else{
			tp=1e9;
			fo(i,0,T-1)key[i]=0;
			printf("%d\n",getans(1,1,n));
		}
	}
	return 0;
}