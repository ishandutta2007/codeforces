#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],fa[N],dis[N],val[N],di[N];
int n,m,q,cnt,x,y,mx;
Vi S[N];
vector<ll> sum[N];
map<pii,db> M;
ll res;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y;
}
void dfs(int x,int fa,int d){
	dis[x]=d;
	di[x]=max(di[x],d);
	if (!mx||dis[x]>dis[mx]) mx=x;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x,d+1);
		}
}
void work(int id){
	mx=0;
	dfs(id,-1,0);
	int tmp=mx;mx=0;
	dfs(tmp,-1,0);
	val[id]=dis[mx];
	tmp=mx;mx=0;
	dfs(tmp,-1,0);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),q=IN();
	For(i,1,n+1) fa[i]=i;
	For(i,1,m+1){
		x=IN(),y=IN();
		Link(x,y);
		Union(x,y);
	}
	For(i,1,n+1) if (fa[i]==i) work(i);
	For(i,1,n+1){
		S[getf(i)].pb(di[i]);
	}
	For(i,1,n+1){
		sort(S[i].begin(),S[i].end());
		sum[i].pb(0);
		For(j,0,S[i].size()){
			sum[i].pb(S[i][j]+sum[i][j]);
		}
	}
	while (q--){
		x=IN(),y=IN();
		x=getf(x),y=getf(y);
		if (x==y){
			puts("-1");
			continue;
		}
		if (S[x].size()>S[y].size()) swap(x,y);
		if (M.count(mp(x,y))){
			printf("%.10lf\n",M[mp(x,y)]);
			continue;
		}
		int tmp=max(val[x],val[y]);
		res=0;
		for (int v:S[x]){
			int pos=lower_bound(S[y].begin(),S[y].end(),tmp-v-1)-S[y].begin();
			res+=1ll*pos*tmp;
			res+=sum[y].back()-sum[y][pos]+1ll*(v+1)*(int(S[y].size()-pos));
		}
		M[mp(x,y)]=1.0*res/int(S[x].size())/int(S[y].size());
		printf("%.10lf\n",M[mp(x,y)]);
	}
}