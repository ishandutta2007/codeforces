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

const int N = 100005;

int n,m,H;
int a[N];
int be[N],siz[N],u;
int dfn[N],k,sta[N],top;
bool pd[N];
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
bool bz[N];
int f[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

void tarjan(int x){
	f[x]=dfn[x]=++k;
	pd[sta[++top]=x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!dfn[e[p].x]){
		tarjan(e[p].x);
		f[x]=min(f[x],f[e[p].x]);
	}
	else if (pd[e[p].x])f[x]=min(f[x],dfn[e[p].x]);
	if (f[x]==dfn[x]){
		u++;
		while(sta[top+1]!=x){
			int y=sta[top];
			be[y]=u;
			siz[u]++;
			pd[y]=0;
			top--;
		}
	}
}

int main(){
	n=get();m=get();H=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,m){
		int x=get(),y=get();
		if ((a[x]+1)%H==a[y])inse(x,y);
		if ((a[y]+1)%H==a[x])inse(y,x);
	}
	fo(i,1,n)
	if (!dfn[i])tarjan(i);
	int key=0;
	fo(i,1,n)
		for(int p=h[i];p;p=e[p].nxt)
		if (be[e[p].x]!=be[i])bz[be[i]]=1;
	fo(i,1,u)
	if (!bz[i]){
		if (!key||siz[key]>siz[i])key=i;
	}
	printf("%d\n",siz[key]);
	fo(i,1,n)
	if (be[i]==key)printf("%d ",i);
	putchar('\n');
	return 0;
}