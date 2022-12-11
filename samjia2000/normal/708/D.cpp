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

const int N = 105;
const int INF = 1e9;

int n,m;
struct EDGE{
	int u,v,c,f;
}eg[N];
struct edge{
	int x,nxt,f,c;
}e[100005];
int h[N],tot;

void addedge(int x,int y,int f,int c){e[++tot].x=y;e[tot].f=f;e[tot].c=c;e[tot].nxt=h[x];h[x]=tot;}

void inse(int x,int y,int f,int c){
	addedge(x,y,f,c);
	addedge(y,x,0,-c);
}

LL dis[N],lst[N];
int que[N];
bool pd[N];
int st,ed;
int co[N];

bool spfa(){
	fo(i,1,n+2)dis[i]=INF,pd[i]=0,lst[i]=0;
	int he=0,ta=1;
	pd[que[1]=st]=1;
	dis[st]=0;
	while(he!=ta){
		int x=que[he=he%(n+2)+1];
		pd[x]=0;
		for(int p=h[x];p;p=e[p].nxt)
		if (e[p].f&&dis[x]+e[p].c<dis[e[p].x]){
			dis[e[p].x]=dis[x]+e[p].c;
			lst[e[p].x]=x;
			co[e[p].x]=p;
			if (!pd[e[p].x])pd[que[ta=ta%(n+2)+1]=e[p].x]=1;
		}
	}
	return dis[ed]!=INF;
}

int aug(){
	int ret=0;
	int f=INF;
	for(int x=ed;x!=st;x=lst[x])f=min(f,e[co[x]].f);
	for(int x=ed;x!=st;x=lst[x]){
		e[co[x]].f-=f;
		e[co[x]^1].f+=f;
	}
	return f*dis[ed];
}

int d[N];

int main(){
	n=get();m=get();
	LL ans=0;
	fo(i,1,m){
		eg[i].u=get();eg[i].v=get();eg[i].c=get();eg[i].f=get();
		d[eg[i].v]+=eg[i].f;
		d[eg[i].u]-=eg[i].f;
	}
	tot=1;
	fo(i,1,m){
		int x=eg[i].u,y=eg[i].v,c=eg[i].c,f=eg[i].f;
		if (c>=f){
			inse(x,y,c-f,1);
			inse(x,y,INF,2);
			inse(y,x,f,1);
		}
		else{
			ans=ans+f-c;
			inse(x,y,INF,2);
			inse(y,x,f-c,0);
			inse(y,x,c,1);
		}
	}
	//n-->1 : INF
	d[1]+=INF,d[n]-=INF;
	st=n+1,ed=n+2;
	inse(1,n,INF*2,0);
	fo(i,1,n)
	if (d[i]!=0){
		if (d[i]>0)inse(st,i,d[i],0);
		else inse(i,ed,-d[i],0);
	}
	while(spfa())ans=ans+aug();
	cout<<ans<<endl;
	return 0;
}