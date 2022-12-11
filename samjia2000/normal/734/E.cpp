#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	bool bz=0;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-')bz=1;else s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (bz)return -s;
	return s;
}

const int N = 2e+5+10;

int col[N],fa[N];
int ed[N][2];
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int n,nl,w,wl,ans;
bool bz[N];

int getfather(int x){
	if (fa[x]==x)return x;
	return fa[x]=getfather(fa[x]);
}

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

void dfs1(int x){
	bz[x]=1;
	if (nl>=wl){
		wl=nl;
		w=x;
	}
	nl++;
	for(int p=h[x];p;p=e[p].nxt)
		if (!bz[e[p].x])
			dfs1(e[p].x);
	nl--;
}

void dfs2(int x){
	bz[x]=0;
	ans=max(ans,nl);
	nl++;
	for(int p=h[x];p;p=e[p].nxt)
		if (bz[e[p].x])dfs2(e[p].x);
	nl--;
}

int main(){
	n=get();
	fo(i,1,n)col[i]=get();
	fo(i,1,n)fa[i]=i;
	fo(i,1,n-1){
		ed[i][0]=get(),ed[i][1]=get();
		int x=getfather(ed[i][0]),y=getfather(ed[i][1]);
		if (col[x]==col[y])fa[x]=y;
	}
	fo(i,1,n-1){
		int x=ed[i][0],y=ed[i][1];
		int tx=getfather(x),ty=getfather(y);
		if (tx!=ty)inse(tx,ty),inse(ty,tx);
	}
	dfs1(getfather(1));
	dfs2(w);
	ans++;
	printf("%d\n",ans/2);
	return 0;
}