#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 105;
const int M = 1005;
const int INF = 1e9;

int n,m,st,ed;
struct edge{
	int x,f,nxt;
}e[M*10];
int h[N],tot;
struct EDGE{
	int x,y,g;
}eg[M];
int que[N];
int dis[N];
struct ANSWER{
	int f,c;
}ans[M];
int be[M*10];
int d[N];
int St,Ed,points;

void addedge(int x,int y,int f){e[++tot].x=y;e[tot].f=f;e[tot].nxt=h[x];h[x]=tot;}

void inse(int x,int y,int f){
	addedge(x,y,f);
	addedge(y,x,0);
}

bool bfs(){
	fo(i,1,points)dis[i]=-1;
	int he=0,ta=1;
	dis[que[1]=st]=0;
	for(;he<ta;){
		int x=que[++he];
		for(int p=h[x];p;p=e[p].nxt)
		if (e[p].f&&dis[e[p].x]==-1){
			dis[e[p].x]=dis[x]+1;
			que[++ta]=e[p].x;
		}
	}
	return dis[ed]!=-1;
}

int aug(int x,int f){
	if (x==ed)return f;
	int ret=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (e[p].f&&dis[e[p].x]==dis[x]+1){
		int tmp=aug(e[p].x,min(f,e[p].f));
		f-=tmp,ret+=tmp;
		e[p].f-=tmp,e[p^1].f+=tmp;
		if (!f)return ret;
	}
	return ret;
}

int main(){
	n=get();m=get();st=get();ed=get();
	tot=1,points=n;
	fo(i,1,m){
		eg[i].x=get();eg[i].y=get();eg[i].g=get();
		int pretot=tot;
		if (eg[i].g)inse(eg[i].x,eg[i].y,1),inse(eg[i].y,eg[i].x,INF);
		else inse(eg[i].x,eg[i].y,INF);
		fo(x,pretot+1,tot)be[x]=i;
	}
	int mxans=0;
	while(bfs())mxans+=aug(st,INF);
	cout<<mxans<<endl;
	
	fo(i,1,n)
	if (dis[i]!=-1){
		for(int p=h[i];p;p=e[p].nxt)
		if (dis[e[p].x]==-1)ans[be[p]].f=ans[be[p]].c=1;
	}
	
	fo(i,0,tot)be[i]=0;
	tot=1,points=n+2;
	St=st,Ed=ed;
	st=n+1,ed=n+2;
	fo(i,1,points)h[i]=0;
	fo(i,1,m)
	if (eg[i].g){
		if (ans[i].f)d[eg[i].x]--,d[eg[i].y]++;
		else{
			d[eg[i].x]--,d[eg[i].y]++;
			be[tot+1]=i;
			inse(eg[i].x,eg[i].y,INF);
		}
	}
	d[St]+=1e5,d[Ed]-=1e5;
	inse(St,Ed,INF);
	fo(i,1,n)
	if (d[i]>0)inse(st,i,d[i]);
	else inse(i,ed,-d[i]);
	while(bfs())aug(st,INF);
	
	fo(i,1,points){
		for(int p=h[i];p;p=e[p].nxt)
		if (be[p]){
			ans[be[p]].f=e[p^1].f+1;
			ans[be[p]].c=ans[be[p]].f+1;
		}
	}
	fo(i,1,m)
	if (!eg[i].g)printf("0 1\n");
	else printf("%d %d\n",ans[i].f,ans[i].c);
	return 0;
}