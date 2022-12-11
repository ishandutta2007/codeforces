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

const int N = 500005;

int n;
struct edg{
	int x,y;
}ed0[N],ed1[N];
struct edge{
	int x,id,nxt;
}e0[N*2],e1[N*2];
int h0[N],tot0,h1[N],tot1;
int ans;
pair<int,int>fans[N];
int co0[N];
int fa[N];

void inse0(int x,int y,int id){e0[++tot0].x=y;e0[tot0].id=id;e0[tot0].nxt=h0[x];h0[x]=tot0;}

void inse1(int x,int y,int id){e1[++tot1].x=y;e1[tot1].id=id;e1[tot1].nxt=h1[x];h1[x]=tot1;}

int que[N],co1[N];

void bfs0(){
	int he=0,ta=1;
	que[1]=1;
	while(he<ta){
		int x=que[++he];
		for(int p=h0[x];p;p=e0[p].nxt)
		if (e0[p].id!=co0[x])co0[que[++ta]=e0[p].x]=e0[p].id;
	}
}

bool diff(edg a,edg b){
	return a.x!=b.x||a.y!=b.y;
}

void bfs1(){
	int he=0,ta=1;
	que[1]=1;
	while(he<ta){
		int x=que[++he];
		if (co0[x])
			if (diff(ed0[co0[x]],ed1[co1[x]]))fans[++ans]=make_pair(co0[x],co1[x]);
		for(int p=h1[x];p;p=e1[p].nxt)
		if (e1[p].id!=co1[x])co1[que[++ta]=e1[p].x]=e1[p].id;
	}
}

bool cmp(edg a,edg b){return a.x==b.x?a.y<b.y:a.x<b.x;}

int getfather(int x){return x==fa[x]?x:fa[x]=getfather(fa[x]);}

int len,dig[20];

void putint(int x){
	len=0;
	for(;x;x=x/10)dig[++len]=x%10;
	for(;len;len--)putchar(dig[len]+'0');
}

int main(){
	n=get();
	fo(i,1,n-1){
		ed0[i].x=get();ed0[i].y=get();
		if (ed0[i].x>ed0[i].y)swap(ed0[i].x,ed0[i].y);
	}
	fo(i,1,n-1){
		ed1[i].x=get();ed1[i].y=get();
		if (ed1[i].x>ed1[i].y)swap(ed1[i].x,ed1[i].y);
	}
	fo(i,1,n)fa[i]=i;
	sort(ed0+1,ed0+n,cmp);
	sort(ed1+1,ed1+n,cmp);
	int w=1;
	fo(i,1,n-1){
		while(w<n-1&&cmp(ed1[w],ed0[i]))w++;
		if(!diff(ed1[w],ed0[i])){
			int x=getfather(ed0[i].x),y=getfather(ed0[i].y);
			if (x>y)swap(x,y);
			fa[y]=x;
		}
	}
	fo(i,1,n-1){
		int x=getfather(ed0[i].x),y=getfather(ed0[i].y);
		if (x!=y)inse0(x,y,i),inse0(y,x,i);
	}
	fo(i,1,n-1){
		int x=getfather(ed1[i].x),y=getfather(ed1[i].y);
		if (x!=y)inse1(x,y,i),inse1(y,x,i);
	}
	bfs0();
	bfs1();
	printf("%d\n",ans);
	fo(i,1,ans){
		putint(ed0[fans[i].fi].x);putchar(' ');
		putint(ed0[fans[i].fi].y);putchar(' ');
		putint(ed1[fans[i].se].x);putchar(' ');
		putint(ed1[fans[i].se].y);putchar('\n');
	}
	return 0;
}