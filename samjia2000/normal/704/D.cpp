#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	int s=0;
	while(ch=getchar(),ch<'0'||ch>'9');
	s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e+5+10;
const int INF = 1e+9;

struct edge{
	int x,f,next;
}e[N*20];
int h[N*2],tot,ss,tt,s,t;
int r,b,n,m,cntr,cntc;
map<int,int>vr,vc;
int totr[N],totc[N],exdr[N],exdc[N],st,ed;
int dis[N*2],q[N*2],vis[N*2],id,cnt[N*2],high[N*2];
struct point{
	int x,y;
}a[N];

void addedge(int x,int y,int f){
	e[++tot].x=y;
	e[tot].f=f;
	e[tot].next=h[x];
	h[x]=tot;
}

void inse(int x,int y,int f){
	addedge(x,y,f);
	addedge(y,x,0);
}

void add(int x,int y,int low,int up){
	if (low){
		inse(ss,y,low);
		inse(x,tt,low);
	}
	inse(x,y,up-low);
//	printf("%d %d %d %d\n",x,y,low,up);
}

int aug(int x,int f){
	if (x==ed)return f;
	int ans=0;
	for(int p=h[x];p;p=e[p].next)
		if (e[p].f&&high[e[p].x]+1==high[x]){
			int o=aug(e[p].x,min(f,e[p].f));
			e[p].f-=o;
			e[p^1].f+=o;
			ans+=o;
			f-=o;
			if (!f)return ans;
		}
	if (!(--cnt[high[x]]))high[st]=ed+1;
	cnt[++high[x]]++;
	return ans;
}

int main(){
	n=get();m=get();r=get();b=get();
	vr.clear();vc.clear();
	fo(i,1,n){
		int x=get(),y=get();
		if (!vr[x])vr[x]=++cntr;
		if (!vc[y])vc[y]=++cntc;
		totr[vr[x]]++;
		totc[vc[y]]++;
		a[i].x=vr[x];a[i].y=vc[y];
	}
	fo(i,1,cntr)exdr[i]=totr[i];
	fo(i,1,cntc)exdc[i]=totc[i];
	tot=1;
	fo(i,1,n)add(a[i].x,cntr+a[i].y,0,1);
	s=0,t=cntr+cntc+1;
	ss=t+1,tt=t+2;
	fo(i,1,m){
		int t=get(),l=get(),d=get();
		if (t==1){
			if (!vr[l])continue;
			exdr[vr[l]]=min(exdr[vr[l]],d);
		}
		else{
			if (!vc[l])continue;
			exdc[vc[l]]=min(exdc[vc[l]],d);
		}
	}
	fo(i,1,cntr){
		int low=(totr[i]-exdr[i])/2+(totr[i]-exdr[i])%2,up=(totr[i]+exdr[i])/2;
		if (low>up){
			printf("-1\n");
			return 0;
		}
		add(s,i,low,up);
	}
	fo(i,1,cntc){
		int low=(totc[i]-exdc[i])/2+(totc[i]-exdc[i])%2,up=(totc[i]+exdc[i])/2;
		if (low>up){
			printf("-1\n");
			return 0;
		}
		add(i+cntr,t,low,up);
	}
	add(t,s,0,INF);
	memset(cnt,0,sizeof(cnt));
	memset(high,0,sizeof(high));
	cnt[0]=tt+1;
	st=ss;ed=tt;
	while(high[ss]<=tt)aug(ss,INF);
	for(int p=h[ss];p;p=e[p].next)
		if (e[p].f){
			printf("-1\n");
			return 0;
		}
	LL ans=0;
	for(int p=h[s];p;p=e[p].next)
		if (e[p].x==t){
			ans=e[p].f;
			break;
		}
	fo(i,s,tt){
		int last=0;
		for(int p=h[i];p;p=e[p].next)
			if (e[p].x==ss||e[p].x==tt){
				if (!last)h[i]=e[p].next;
				else e[last].next=e[p].next;
			}
			else last=p;
	}
	int last=0;
	for(int p=h[s];p;p=e[p].next)
		if (e[p].x==t){
			if(!last)h[s]=e[p].next;
			else e[last].next=e[p].next;
		}
		else last=p;
	last=0;
	for(int p=h[t];p;p=e[p].next)
		if (e[p].x==s){
			if(!last)h[t]=e[p].next;
			else e[last].next=e[p].next;
		}
		else last=p;
	memset(cnt,0,sizeof(cnt));
	memset(high,0,sizeof(high));
	cnt[0]=t+1;
	st=s;ed=t;
	while(high[s]<=t)ans+=aug(s,INF);
	char s1='r',s2='b';
	if (r>b){
		swap(r,b);
		swap(s1,s2);
	}
	printf("%I64d\n",ans*r+LL(n-ans)*b);
	fo(i,1,n){
		int x=a[i].x,y=a[i].y;
		bool bz=0;
		if (!e[i*2].f)bz=1;
		if (bz)putchar(s1);
		else putchar(s2);
	}
	return 0;
}