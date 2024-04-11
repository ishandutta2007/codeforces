#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
const int N=510000;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n;
vector<int> go[N];
int a[N],fa[N],q[N],dep[N];
int ff[20][N];
int bg[N];
int fr[N];
void setleast(int a,int x){
	if(fr[a]&&fr[a]!=x){
		printf("0\n");
		exit(0);
	}
	fr[a]=x;
}
void setmost(int a,int x){
	if(bg[a]&&bg[a]!=x){
		printf("0\n");
		exit(0);
	}
	bg[a]=x;
}
int getk(int x,int k){
	//printf("___%d %d\n",x,k);
	per(i,19,0)if((1<<i)&k)x=ff[i][x];
	return x;
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	per(i,19,0)if((1<<i)&(dep[a]-dep[b]))a=ff[i][a];
	if(a==b)return a;
	per(i,19,0)if(ff[i][a]^ff[i][b]){
		a=ff[i][a];
		b=ff[i][b];
	}
	return fa[a];
}
vector<pii> spe[N];

int w[N][2];
void addtag(int s,int a,int b){
	//printf("___%d %d %d\n",s,a,b);
	w[a][s]++;
	w[fa[b]][s]--;
}
int aft[N];
int bef[N];
bool vis[N];
int fac[N];
int calc(int S){
	if(0){
		printf("c %d\n",S);
		for(pii w:spe[S])printf("%d %d\n",w.fi,w.se);
		printf("__%d %d\n",bg[S],fr[S]);
	}
	//spe: pii(a,b): ab
	//bg[x]:		 
	//fr[x]:		 

	if(go[S].size()==1)return 1;

	for(int y:go[S])aft[y]=bef[y]=vis[y]=0;
	for(pii w:spe[S]){
		if(aft[w.se]&&aft[w.se]!=w.fi)return 0;
		aft[w.se]=w.fi;
		if(bef[w.fi]&&bef[w.fi]!=w.se)return 0;
		bef[w.fi]=w.se;
	}
	if(bg[S])if(bef[bg[S]])return 0;
	if(fr[S])if(aft[fr[S]])return 0;
	//printf("stay %d\n",S);
	int blk=0;
	bool same=0;
	int all=0;
	for(int y:go[S])if(!vis[y])if(!bef[y]){
		//printf("arr %d\n",y);
		int bgin=0;
		++blk;
		int frin=0;
		int x=y;
		for(;(!vis[x])&&x;x=aft[x]){
			vis[x]=1;
			++all;
			if(x==bg[S])bgin=1;
			if(x==fr[S])frin=1;
		}
		//printf("s %d %d\n",y,x);
		if(x)return 0;
		if(bgin&&frin)same=1;
	}
	if(all!=go[S].size())return 0;
	if(blk>1&&same)return 0;
	if(blk==1)return 1;
	if(bg[S])blk--;
	if(fr[S])blk--;
	//printf("res ____%d\n",blk);
	return fac[blk];
}
void clk(){
	per(i,q[0],1){
		int x=q[i];
		for(int y:go[x])if(fa[y]==x){
			rep(j,0,1)w[x][j]+=w[y][j];
		}
	}
	rep(x,1,n){
		if(w[x][0]&&w[x][1]){
			printf("0\n");
			return;
		}
		if(w[x][0]){
			spe[fa[x]].pb(pii(x,fa[fa[x]]));
		}
		if(w[x][1]){
			spe[fa[x]].pb(pii(fa[fa[x]],x));
		}
	}
	int ans=1;
	rep(i,1,n){
		ans=ans*1ll*calc(i)%P;
		//printf("aft %d:%d\n",i,ans);
	}
	printf("%d\n",ans);
}
void addlink(int a,int b){
	int d=lca(a,b);
	//printf("lca %d\n",d);
	//setmost

	if(a==d){
		int ss=getk(b,dep[b]-dep[d]-1);
		setleast(a,ss);
	}
	else{
		setleast(a,fa[a]);
	}

	if(b==d){
		int ss=getk(a,dep[a]-dep[d]-1);
		setmost(b,ss);
	}
	else{
		setmost(b,fa[b]);
	}

	//addlink
	//a....d
	if(dep[a]-dep[d]>=2){
		addtag(0,a,getk(a,dep[a]-dep[d]-2));
	}

	//b...d
	if(dep[b]-dep[d]>=2){
		//printf("__%d %d\n",b,dep[b]-dep[d]-2);
		addtag(1,b,getk(b,dep[b]-dep[d]-2));
	}

	if(a!=d&&b!=d){
		spe[d].pb(pii(getk(a,dep[a]-dep[d]-1),getk(b,dep[b]-dep[d]-1)));
	}
}
int main(){
	scanf("%d",&n);
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);
		go[a].pb(b);go[b].pb(a);
	}
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(i==a[i]){
			printf("0\n");
			return 0;
		}
	}
	q[q[0]=1]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int y:go[x]){
			if(fa[x]==y)continue;
			dep[y]=dep[x]+1;
			fa[y]=x;
			q[++q[0]]=y;
		}
	}
	rep(i,1,n)ff[0][i]=fa[i];
	rep(j,1,19)rep(i,1,n)ff[j][i]=ff[j-1][ff[j-1][i]];

	rep(i,1,n)if(a[i]){
		addlink(i,a[i]);
	}
	clk();
	return 0;
}