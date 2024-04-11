#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=100000+19;
const int p=1e9+7;

struct Edge{
	int y,a,b,nxt;
} E[N*2];

Vi V[N];
int las[N],d[N],use[N],vis[N];
int f[N][2][2],g[N][2][2][2];
int res[2],val[2],tmp[2];
int n,m,x,y,a,b,k,cnt,pt,T=1,Ans,Time;

int sgn(int x){
	return x>0?0:1;
}
void Upd(){
	tmp[0]=(1ll*res[0]*val[0]+1ll*res[1]*val[1])%p;
	tmp[1]=(1ll*res[0]*val[1]+1ll*res[1]*val[0])%p;
	For(i,0,2) res[i]=tmp[i];
}
void Link(int x,int y,int a,int b){
	E[cnt]=(Edge){y,a,b,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,b,a,las[y]};las[y]=cnt++;
}
void dfs(int x){
	int c=0;
	vis[x]=1;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (!vis[y=E[i].y]){
			c++;
			For(s,0,2) For(t,0,2) For(o,0,2){
				(f[y][t][o^(s^E[i].a|t^E[i].b)]+=f[x][s][o])%=p;
			}
			dfs(y);
		}
	if (c==0){
		if (V[x].size()==1){
			For(s,0,2) For(o,0,2) (val[o^(s^V[x][0])]+=f[x][s][o])%=p;
		} else{
			For(s,0,2) For(o,0,2) (val[o]+=f[x][s][o])%=p;
		}
	}
}
void calc_1(int x){
	if (V[x].size()==1){
		For(t,0,2) f[x][t][t^V[x][0]]++;
	} else{
		For(t,0,2) f[x][t][0]++;
	}
	For(t,0,2) val[t]=0;
	dfs(x);
	Upd();
}
void dfs(int x,int fa){
	vis[x]=++Time;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (i!=fa){
			y=E[i].y;
			if (vis[y]){
				if (vis[y]<vis[x]){
					For(u,0,2) For(s,0,2) For(o,0,2){
						(val[o^(s^E[i].a|u^E[i].b)]+=g[x][u][s][o])%=p;
					}
				}
			} else{
				For(u,0,2) For(s,0,2) For(t,0,2) For(o,0,2){
					(g[y][u][t][o^(s^E[i].a|t^E[i].b)]+=g[x][u][s][o])%=p;
				}
				dfs(y,i^1);
			}
		}
}
void calc_2(int x){
	For(t,0,2) g[x][t][t][0]++;
	For(t,0,2) val[t]=0;
	dfs(x,-1);
	Upd();
}

int main(){
	memset(las,-1,sizeof(las));
	m=IN(),n=IN();
	For(i,0,m){
		k=IN();
		if (k==1){
			x=IN();a=abs(x);
			use[a]=1;
			V[a].pb(sgn(x));
		} else{
			x=IN(),y=IN();
			a=abs(x),b=abs(y);
			use[a]=1;use[b]=1;
			if (a!=b){
				Link(a,b,sgn(x),sgn(y));
				d[a]++;d[b]++;
			} else{
				if (x==y){
					V[a].pb(sgn(x));
				} else{
					use[a]=0;
					T^=1;
				}
			}
		}
	}
	res[0]=1;
	For(x,1,n+1)
		if (d[x]==0){
			if (V[x].size()==2){
				For(i,0,2) val[i]=0;
				val[V[x][0]^V[x][1]]+=2;
				Upd();
			} else
			if (V[x].size()==1){
				For(i,0,2) val[i]=1;
				Upd();
			}
		}
	For(i,1,n+1) if (d[i]==1&&!vis[i]) calc_1(i);
	For(i,1,n+1) if (d[i]==2&&!vis[i]) calc_2(i);
	Ans=res[T];
	For(i,1,n+1){
		if (!use[i]) Ans=2ll*Ans%p;
	}
	printf("%d\n",Ans);
}