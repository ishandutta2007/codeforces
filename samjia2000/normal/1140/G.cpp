#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

LL get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		LL s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	LL s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;

int n;
LL tr[N];
struct edge{
	int x,nxt;
	LL w1,w2;
}e[N*2];
int h[N],tot;
struct matrix{
	LL a[2][2];
	
	LL * operator [](int x){return a[x];}
	
	void init(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=1e18;}
	
	friend matrix operator *(matrix a,matrix b){
		matrix c;
		fo(i,0,1)fo(j,0,1)c[i][j]=1e18;
		fo(i,0,1)
			fo(j,0,1)
				fo(k,0,1)
				c[i][k]=min(c[i][k],a[i][j]+b[j][k]);
		return c;
	}	
};
int fa[N][20],dep[N];

void inse(int x,int y,LL w1,LL w2){e[++tot].x=y;e[tot].w1=w1;e[tot].w2=w2;e[tot].nxt=h[x];h[x]=tot;}

LL co1[N],co2[N];
int que[N],k;

void dfs(int x){
	que[++k]=x;
	fo(i,1,19)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int p=h[x];p;p=e[p].nxt)
		if (!dep[e[p].x]){
			int y=e[p].x;
			fa[y][0]=x;
			dep[y]=dep[x]+1;
			co1[y]=e[p].w1;
			co2[y]=e[p].w2;
			dfs(y);
		}
}

void multi(LL *px,matrix t,LL *ret){
	LL tmp[2];
	tmp[0]=tmp[1]=1e18;
	fo(a,0,1)fo(b,0,1)tmp[b]=min(tmp[b],px[a]+t[a][b]);
	ret[0]=tmp[0],ret[1]=tmp[1];
}

matrix f[N][20];

struct node{
	int x;
	LL v;
	node(const int x_=0,const LL v_=0){x=x_;v=v_;}
	friend bool operator <(node a,node b){return a.v!=b.v?a.v<b.v:a.x<b.x;}
};
set<node>st;

void gettr(){
	st.clear();
	fo(x,1,n)st.insert(node(x,tr[x]));
	fo(rd,1,n){
		int x=(*st.begin()).x;
		st.erase(st.begin());
		for(int p=h[x];p;p=e[p].nxt){
			int y=e[p].x;
			if (tr[y]>tr[x]+e[p].w1+e[p].w2){
				st.erase(node(y,tr[y]));
				tr[y]=tr[x]+e[p].w1+e[p].w2;
				st.insert(node(y,tr[y]));
			}
		}
	}
}

int main(){
	n=get();
	fo(i,1,n)tr[i]=get();
	fo(i,2,n){
		int x=get(),y=get();
		LL w1=get(),w2=get();
		inse(x,y,w1,w2);
		inse(y,x,w1,w2);
	}
	gettr();
	dep[1]=1;
	dfs(1);
	fo(p,1,n){
		int x=que[p];
		if (x==1)continue;
		int y=fa[x][0];
		f[x][0][0][0]=min(tr[x]+tr[y]+co2[x],co1[x]);
		f[x][0][1][1]=min(tr[x]+tr[y]+co1[x],co2[x]);
		f[x][0][0][1]=min(co1[x]+tr[y],tr[x]+co2[x]);
		f[x][0][1][0]=min(co2[x]+tr[y],tr[x]+co1[x]);
		fo(i,1,19)f[x][i]=f[x][i-1]*f[fa[x][i-1]][i-1];
	}
	int q=get();
	fo(cas,1,q){
		int u=get(),v=get();
		int x=(u+1)/2,y=(v+1)/2;
		LL px[2],py[2];
		if (u&1)px[0]=0,px[1]=tr[x];
		else px[1]=0,px[0]=tr[x];
		if (v&1)py[0]=0,py[1]=tr[y];
		else py[1]=0,py[0]=tr[y];
		LL tmp[2];
		if (dep[x]>dep[y]){
			fd(i,19,0)
			if (dep[fa[x][i]]>=dep[y]){
				multi(px,f[x][i],px);
				x=fa[x][i];
			}
		}
		if (dep[y]>dep[x]){
			fd(i,19,0)
			if (dep[fa[y][i]]>=dep[x]){
				multi(py,f[y][i],py);
				y=fa[y][i];
			}
		}
		//x,y --> lca
		fd(i,19,0)
		if (fa[x][i]!=fa[y][i]){
			multi(px,f[x][i],px);
			x=fa[x][i];
			multi(py,f[y][i],py);
			y=fa[y][i];
		}
		if (x!=y){
			multi(px,f[x][0],px);
			multi(py,f[y][0],py);
			x=fa[x][0],y=fa[y][0];
		}
		LL ans=min(px[0]+py[0],px[1]+py[1]);
		printf("%I64d\n",ans);
	}
	return 0;
}