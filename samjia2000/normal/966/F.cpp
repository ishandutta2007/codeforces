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

const int N = 4005;
const int M = 2e5+5;
const db eps = 1e-9;
const db EPS = 1e-7;

int n,m;
int S,T;
int h[N],tot;
struct edge{
	int x,c,nxt;
	db f;
}e[M];
struct EDGE{
	int a,b,c,d,x,y;
	void init(){
		x=get();y=get();a=get();b=get();c=get();d=get();
	}
}ed[N];

void addedge(int x,int y,db f,int c){e[++tot].x=y;e[tot].c=c;e[tot].f=f;e[tot].nxt=h[x];h[x]=tot;}

void inse(int x,int y,db f,int c){
	addedge(x,y,f,c);
	addedge(y,x,0,0);
}

int dis[N];
int que[N];

bool bfs(){
	fo(i,1,n+2)dis[i]=-1;
	int he=0,ta=1;
	dis[que[1]=S]=1;
	for(;he<ta;){
		int x=que[++he];
		for(int p=h[x];p;p=e[p].nxt)
		if (e[p].f>eps&&dis[e[p].x]==-1){
			dis[e[p].x]=dis[x]+1;
			que[++ta]=e[p].x;
		}
	}
	return dis[T]!=-1;
}

db aug(int x,db f){
	if (x==T)return f;
	db ret=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (dis[e[p].x]==dis[x]+1&&e[p].f>eps){
		db o=aug(e[p].x,min(f,e[p].f));
		f-=o,ret+=o;
		e[p].f-=o;
		e[p^1].f+=o;
	}
	return ret;
}

pair<int,bool> check(db t){
	tot=1;
	fo(i,1,n+2)h[i]=0;
	S=n+1,T=n+2;
	db sum=0;
	fo(i,1,m){
		int x=ed[i].x,y=ed[i].y;
		db l=t*ed[i].a+ed[i].b,r=t*ed[i].c+ed[i].d;
		sum=sum+l;
		inse(S,y,l,ed[i].a);
		inse(x,T,l,ed[i].a);
		inse(x,y,r-l,ed[i].c-ed[i].a);
	}
	db ans=0;
	while(bfs())ans=ans+aug(S,1e9);
	if (fabs(ans-sum)<eps)return make_pair(0,true);
	pair<db,bool>ret=make_pair(0,false);
	fo(x,1,n+2)
	if (dis[x]!=-1){
		for(int p=h[x];p;p=e[p].nxt)
		if (dis[e[p].x]==-1)ret.first=ret.first+e[p].c;
	}
	fo(i,1,m)ret.first=ret.first-ed[i].a;
	return ret;
}

int main(){
	n=get();m=get();
	fo(i,1,m)ed[i].init();
	db lt=-1,rt=-1;
	db l=0,r=1;
	fo(T,1,50){
		db mid=(l+r)/2;
		pair<db,bool>u=check(mid);
		if (u.second)lt=mid,r=mid;
		else{
			if (u.first>0)l=mid;
			else r=mid;
		}
	}
	l=0,r=1;
	fo(T,1,50){
		db mid=(l+r)/2;
		pair<db,bool>u=check(mid);
		if (u.second)rt=mid,l=mid;
		else{
			if (u.first>0)l=mid;
			else r=mid;
		}
	}
	if (lt<0)printf("0\n");
	else printf("%.9lf\n",rt-lt);
	return 0;
}