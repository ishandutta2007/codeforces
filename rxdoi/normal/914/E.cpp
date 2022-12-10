#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e5+19;
const int oo=(1<<30)-1;

int Time;

struct Hash{
	#define N 15000000
	#define p 1000007
	int T[p],las[p],key[N],val[N],nxt[N];
	int c;
	void Ins(int x){
		if (T[x%p]!=Time) T[x%p]=Time,las[x%p]=-1;
		for (int i=las[x%p];~i;i=nxt[i])
			if (key[i]==x){
				val[i]++;
				return;
			}
		key[c]=x;
		val[c]=1;
		nxt[c]=las[x%p];
		las[x%p]=c++;
	}
	int Qry(int x){
		if (T[x%p]!=Time) T[x%p]=Time,las[x%p]=-1;
		for (int i=las[x%p];~i;i=nxt[i]){
			if (key[i]==x) return val[i];
		}
		return 0;
	}
	#undef p
	#undef N
} H;

struct Edge{
	int y,nxt;
} E[N*2];
ll ans[N],sum[N];
int las[N],vis[N],sz[N];
int n,cnt,mn,cen,fcen;
char s[N];

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void findcen(int x,int fa,int n){
	sz[x]=1;
	sum[x]=0;
	int tmp=0;
	Rep(x) if (y!=fa){
		findcen(y,x,n);
		sz[x]+=sz[y];
		tmp=max(tmp,sz[y]);
	}
	tmp=max(tmp,n-sz[x]);
	if (tmp<mn) mn=tmp,cen=x,fcen=fa;
}
void dfs_Qry(int x,int fa,int v){
	v^=1<<s[x]-'a';
	sum[x]+=H.Qry(v);
	For(w,0,26) sum[x]+=H.Qry(v^(1<<w));
	Rep(x) if (y!=fa) dfs_Qry(y,x,v);
}
void dfs_Ins(int x,int fa,int v){
	v^=1<<s[x]-'a';
	H.Ins(v);
	Rep(x) if (y!=fa) dfs_Ins(y,x,v);
}
void dfs(int x,int fa){
	Rep(x) if (y!=fa){
		dfs(y,x);
		sum[x]+=sum[y];
	}
	ans[x]+=sum[x];
}
void solve(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	Vi V;
	Rep(x) V.pb(y);
	Time++;
	H.Ins(1<<s[x]-'a');
	for (int y:V){
		dfs_Qry(y,x,0);
		dfs_Ins(y,x,1<<s[x]-'a');
	}
	reverse(V.begin(),V.end());
	Time++;
	for (int y:V){
		dfs_Qry(y,x,0);
		dfs_Ins(y,x,1<<s[x]-'a');
	}
	ll alb=0;
	alb+=H.Qry(0);
	For(w,0,26) alb+=H.Qry(1<<w);
	Rep(x){
		dfs(y,x);
		alb+=sum[y];
	}
	assert(alb%2==0);
	ans[x]+=alb/2;
	Rep(x) solve(y,sz[y]);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	scanf("%s",s+1);
	solve(1,n);
	For(i,1,n+1){
		printf("%I64d ",ans[i]+1);
	}
	puts("");
}