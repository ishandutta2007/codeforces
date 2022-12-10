#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

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

struct Point{
	int x,y;
	bool operator < (const Point &B) const{
		return x<B.x;
	}
} P[N*2];

struct QType{
	int x,f,l,r,id;
	bool operator < (const QType &B) const{
		return x<B.x;
	}
} Q[N*2];

struct Edge{
	int y,nxt;
} E[N];
int las[N],dep[N],I[N],O[N],fa[20][N],go[20][N];
int a[N],b[N],bao[N],val[N],ans[N];
int n,m,q,u,v,cnt,tot,qc,pc;
int Qxl,Qxr,Qyl,Qyr,res;

int sum[N];

void Add(int x,int v){
	for (;x<=n;x+=x&-x) sum[x]+=v;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=sum[x];
	return res;
}

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
}
void dfs(int x){
	I[x]=++tot;
	for (int i=las[x],y;~i;i=E[i].nxt){
		y=E[i].y;
		fa[0][y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
	}
	O[x]=tot;
}
int LCA(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=0,k=dep[y]-dep[x];k;k>>=1,i++) if (k&1) y=fa[i][y];
	if (x==y) return x;
	for (int i=19;~i;i--) if (fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void jump(int &y,int x,int &ans){
	for (int i=19;~i;i--){
		if (dep[go[i][y]]>dep[x]) ans+=1<<i,y=go[i][y];
	}
}
int work(int id,int x,int y){
	if (x==y) return 0;
	if (dep[x]>dep[y]) swap(x,y);
	if (I[x]<=I[y]&&I[y]<=O[x]){
		if (dep[go[19][y]]>dep[x]) return -1;
		int ans=0;
		jump(y,x,ans);
		return ans+1;
	}
	int z=LCA(x,y);
	if (dep[go[19][x]]>dep[z]||dep[go[19][y]]>dep[z]) return -1;
	int ans=0;
	jump(x,z,ans);
	jump(y,z,ans);
	Q[++qc]=(QType){I[x]-1,-1,I[y],O[y],id};
	Q[++qc]=(QType){O[x],1,I[y],O[y],id};
	bao[id]=1;
	/*
	Qxl=I[x],Qxr=O[x];
	Qyl=I[y],Qyr=O[y];
	Query(1,1,n);
	if (res) return ans+1;else return ans+2;
	*/
	return ans;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,2,n+1) Add_Edge(IN(),i);
	dep[1]=1;
	dfs(1);
	For(i,1,20){
		For(x,1,n+1) fa[i][x]=fa[i-1][fa[i-1][x]];
	}
	For(i,1,n+1) go[0][i]=i;
	m=IN();
	For(i,1,m+1){
		a[i]=IN(),b[i]=IN();
		P[++pc]=(Point){I[a[i]],I[b[i]]};
		P[++pc]=(Point){I[b[i]],I[a[i]]};
		//Insert(1,1,n,I[a[i]],I[b[i]]);
		//Insert(1,1,n,I[b[i]],I[a[i]]);
		int c=LCA(a[i],b[i]);
		if (dep[c]<dep[go[0][a[i]]]) go[0][a[i]]=c;
		if (dep[c]<dep[go[0][b[i]]]) go[0][b[i]]=c;
	}
	for (int i=n;i>1;i--){
		if (dep[go[0][i]]<dep[go[0][fa[0][i]]]){
			go[0][fa[0][i]]=go[0][i];
		}
	}
	For(i,1,20){
		For(x,1,n+1) go[i][x]=go[i-1][go[i-1][x]];
	}
	q=IN();
	For(i,1,q+1){
		u=IN(),v=IN();
		ans[i]=work(i,u,v);
	}
	sort(Q+1,Q+qc+1);
	sort(P+1,P+pc+1);
	int c=1;
	For(i,1,qc+1){
		for (;c<=pc&&P[c].x<=Q[i].x;c++){
			Add(P[c].y,1);
		}
		val[Q[i].id]+=Q[i].f*(Qry(Q[i].r)-Qry(Q[i].l-1));
	}
	For(i,1,q+1) if (bao[i]){
		ans[i]+=(val[i]>0?1:2);
	}
	For(i,1,q+1) printf("%d\n",ans[i]);
}