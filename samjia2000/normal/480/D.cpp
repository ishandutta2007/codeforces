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

const int N = 510;
const int L = 1010;

struct parcel{
	int st,ed,w,s,v;
	friend bool operator < (parcel a,parcel b){
		return a.ed-a.st<b.ed-b.st;
	}
}a[N];
int n,S;
int f[N][L],g[L][L];
int lst[L];
struct edge{
	int x,nxt;
}e[N*N];
int h[N],tot;
int fa[N];
int w[N],k;

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

bool cmp(int x,int y){
	if (a[x].ed!=a[y].ed)return a[x].ed<a[y].ed;
	return a[x].st<a[y].st;
}

void solve(){
	sort(w+1,w+1+k,cmp);
	int now=1;
	fo(i,1,2*n)lst[i]=0;
	fo(i,1,k)lst[a[w[i]].ed]=a[w[i]].ed;
	fo(i,1,2*n)lst[i]=max(lst[i],lst[i-1]);
	fo(i,1,2*n)
	if (lst[i]==i){
		fo(j,0,S)g[i][j]=0;
		while(now<=k&&a[w[now]].ed==i){
			g[i][0]=max(g[i][0],g[lst[a[w[now]].st]][0]+f[w[now]][0]);
			fo(j,1,S)g[i][j]=max(g[i][j],max(g[lst[a[w[now]].st]][j]+f[w[now]][j],g[i][j-1]));
			now++;
		}
		fo(j,1,S)g[i][j]=max(g[lst[i-1]][j],g[i][j]);
	}
}

int main(){
	n=get();S=get();
	fo(i,1,n){a[i].st=get();a[i].ed=get();a[i].w=get();a[i].s=get();a[i].v=get();}
	sort(a+1,a+1+n);
	fo(i,1,n)
		fo(j,1,i-1)
		if (a[i].st<=a[j].st&&a[j].ed<=a[i].ed){
			inse(i,j);
		}
	fo(i,1,n){
		k=0;
		for(int p=h[i];p;p=e[p].nxt)w[++k]=e[p].x;
		solve();
		int q=lst[2*n];
		fo(j,0,S)f[i][j]=g[q][j];
		fd(j,min(S-a[i].w,a[i].s),0)
		f[i][j+a[i].w]=max(f[i][j+a[i].w],f[i][j]+a[i].v);
		fo(j,1,S)f[i][j]=max(f[i][j],f[i][j-1]);
	}
	k=0;
	fo(i,1,n)
	if (!fa[i])w[++k]=i;
	solve();
	int q=lst[2*n];
	printf("%d\n",g[q][S]);
	return 0;
}