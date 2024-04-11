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

const int N = 1e6+5;
const int K = 25;
const int L = (1<<20)+5;

int n,m;
struct edge{
	int x,nxt;
}e[N];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int f[K],g[K];
int can[K];
int in[N],out[N];
int id[N],k1,k2;
int vis[N],tim;
int st;

void dfs(int x){
	vis[x]=tim;
	if (!out[x])can[id[x]]|=(1<<(st-1));
	for(int p=h[x];p;p=e[p].nxt)
	if (vis[e[p].x]<tim)dfs(e[p].x);
}

int cnt[L];

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		out[x]++,in[y]++;
		inse(x,y);
	}
	fo(i,1,n)if (!out[i])g[id[i]=++k2]=i;
	fo(i,1,n)if (!in[i])f[id[i]=++k1]=i;
	int k=k1;
	fo(i,1,k){
		int x=f[i];
		tim++;
		st=i;
		dfs(x);
	}
	bool ans=1;
	fo(i,1,(1<<k)-1)cnt[i]=cnt[i-(i&-i)]+1;
	fo(i,1,(1<<k)-2){
		int all=0;
		fo(x,1,k)if ((i&(1<<(x-1)))>0)all|=can[x];
		if(cnt[all]<=cnt[i]){ans=0;break;}
	}
	if (ans)printf("YES\n");else printf("NO\n");
	return 0;
}