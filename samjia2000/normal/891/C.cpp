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
#define se second
#define fi first

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

const int N = 5e+5+5;
const int INF = 1e+9;

int n,m;
int fa[N],h[N];
struct cg{
	int x,fa,h;
	cg(const int x_=0,const int fa_=0,const int h_=0){x=x_;fa=fa_;h=h_;}
}c[N*2];
int u;
struct edge{
	int x,y,v;
	edge(const int x_=0,const int y_=0,const int v_=0){x=x_;y=y_;v=v_;}
	friend bool operator <(edge a,edge b){return a.v<b.v;}
}e[N];
struct query{
	int x,y,v,be;
	query(const int x_=0,const int y_=0,const int v_=0,const int be_=0){x=x_;y=y_;v=v_;be=be_;}
	friend bool operator < (query a,query b){
		if (a.v!=b.v)return a.v<b.v;
		return a.be<b.be;
	}
}qry[N];
int q,k;
bool ans[N];
int val[N],F[N];

int getfather(int x){return fa[x]==x?x:getfather(fa[x]);}
int getF(int x){return F[x]==x?x:getF(F[x]);}

int sa[N],sb[N],ka,kb;

int getval(int x,int y){
	if (x==y)return -INF;
	ka=kb=0;
	for(;x!=F[x];x=F[x])sa[++ka]=x;
	for(;y!=F[y];y=F[y])sb[++kb]=y;
	reverse(sa+1,sa+1+ka);
	reverse(sb+1,sb+1+kb);
	fo(i,ka+1,kb)sa[i]=0;
	fo(i,kb+1,ka)sb[i]=0;
	int w;
	fo(i,1,max(ka,kb))
	if (sa[i]!=sb[i]){w=i;break;}
	int v=0;
	fo(i,w,ka)v=max(v,val[sa[i]]);
	fo(i,w,kb)v=max(v,val[sb[i]]);
	return v;
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get(),v=get();
		e[i]=edge(x,y,v);
	}
	q=get();
	fo(i,1,q){
		int t=get();
		ans[i]=1;
		fo(j,k+1,k+t){
			int p=get();
			qry[j]=query(e[p].x,e[p].y,e[p].v,i);
		}
		k+=t;
	}
	sort(e+1,e+1+m);
	sort(qry+1,qry+1+k);
	fo(i,1,n)fa[i]=i,h[i]=0;
	int w=1;
	e[0].v=-1;
	fo(i,1,m){
		if (e[i].v>e[i-1].v){
			while(w<=k&&qry[w].v==e[i].v){
				u=0;
				int be=qry[w].be;
				while(w<=k&&qry[w].be==be&&qry[w].v==e[i].v){
					int x=getfather(qry[w].x),y=getfather(qry[w].y);
					if (x==y)ans[be]=0;
					else{
						if (h[x]<h[y])swap(x,y);
						c[++u]=cg(y,fa[y],h[y]);
						c[++u]=cg(x,fa[x],h[x]);
						h[x]=max(h[x],h[y]+1);
						fa[y]=x;
					}
					w++;
				}
				fd(j,u,1){
					fa[c[j].x]=c[j].fa;
					h[c[j].x]=c[j].h;
				}
			}
		}
		int x=getfather(e[i].x),y=getfather(e[i].y);
		if (h[x]<h[y])swap(x,y);
		if (x==y)continue;
		h[x]=max(h[x],h[y]+1);
		fa[y]=x;
	}
	fo(i,1,q)if (ans[i])printf("YES\n");else printf("NO\n");
	return 0;
}