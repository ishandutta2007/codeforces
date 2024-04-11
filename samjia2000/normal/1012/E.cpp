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
#define fi first
#define se second

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

int n,s;
int a[N],b[N];
int to[N];
int q;
bool vis[N];
struct edge{
	int x,id,nxt;
}e[N];
int h[N],tot;
int col[N];
map<int,int>id;
int k;

void inse(int x,int y,int id){e[++tot].x=y;e[tot].id=id;e[tot].nxt=h[x];h[x]=tot;}

bool used[N];
int st;
int u;
int que[N];
pair<int,int>key[N];
int be[N];

void euler(int x){
	for(;h[x];){
		int p=h[x];
		int id=e[p].id;
		int y=e[p].x;
		que[++u]=id;
		h[x]=e[p].nxt;
		euler(y);
	}
}
int fa[N],c;

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void add(int l,int r,int c){
	to[l]=r;
	int x=id[a[l]];
	if (be[x]&&getfather(be[x])==getfather(c))return;
	int fx=getfather(be[x]),fc=getfather(c);
	if (!key[x].fi)be[x]=c,key[x]=make_pair(l,r);
	else{
		to[l]=key[x].se;
		to[key[x].fi]=r;
		key[x].fi=l;
		fa[fx]=fc;
	}
}


void getto(){
	c=0;
	for(int l=1;l<=u;){
		int r=l;
		c++;
		fa[c]=c;
		for(;a[que[r]]!=b[que[l]];r++);
		int st=id[b[que[l]]];
		fo(i,l,r-1){
			add(que[i],que[i+1],c);
		}
		add(que[r],que[l],c);
		l=r+1;
	}
}

int Fa[N];

int getFa(int x){return Fa[x]==x?x:Fa[x]=getFa(Fa[x]);}

void merge(int x,int y){
	int tx=getFa(x),ty=getFa(y);
	Fa[tx]=ty;
}

bool ad[N];
int kp[N];
int pv[N];

int main(){
	n=get();s=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)b[i]=a[i];
	sort(b+1,b+1+n);
	int len=n;
	fo(i,1,n)if (b[i]==a[i])to[i]=i,len--;
	if (len>s)return printf("-1\n"),0;
	s-=len;
	fo(i,1,n)if (!id[b[i]])col[id[b[i]]=++k]=b[i];
	fo(i,1,k)Fa[i]=i;
	fo(i,1,n){
		int x=id[a[i]],y=id[b[i]];
		int tx=getFa(x),ty=getFa(y);
		if (tx==ty){
			ad[i]=1;
			continue;
		}
		Fa[tx]=ty;
	}
	fo(i,1,n)
	if (ad[i]&&a[i]!=b[i]){
		int x=getFa(id[a[i]]);
		if (!kp[x])kp[x]=i;
	}
	int nq=0;
	fo(i,1,k)if (getFa(i)==i&&kp[i])nq++;
	bool predo=0;
	int pl=0;
	if (nq>1&&s>1){
		predo=1;
		fo(i,1,k)
		if (getFa(i)==i&&kp[i]){
			if (s){
				pv[++pl]=kp[i];
				s--;
			}
		}
		if (pl<=1)predo=0;
		else{
			int tmp=a[pv[pl]];
			fd(i,pl,2)a[pv[i]]=a[pv[i-1]];
			a[pv[1]]=tmp;
		}
	}
	fo(i,1,n)
	if (a[i]!=b[i])inse(id[b[i]],id[a[i]],i);
	fo(i,1,n){
		st=i;
		u=0;
		euler(i);
		getto();
	}
	int q=0;
	fo(i,1,n)
	if (a[i]!=b[i]&&!vis[i]){
		q++;
		vis[i]=1;
		for(int x=to[i];x!=i;x=to[x])vis[x]=1;
	}
	printf("%d\n",q+predo);
	//return 0;
	if (predo){
		printf("%d\n",pl);
		fo(i,1,pl)printf("%d ",pv[i]);
		putchar('\n');
	}
	fo(i,1,n)
	if (a[i]!=b[i]&&vis[i]){
		int len=1;
		vis[i]=0;
		for(int x=to[i];x!=i;x=to[x])vis[x]=0,len++;
		printf("%d\n%d",len,i);
		for(int x=to[i];x!=i;x=to[x])printf(" %d",x);
		putchar('\n');
	}
	return 0;
}