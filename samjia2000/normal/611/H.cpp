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

const int N = 2e5+5;
const int INF = 1e9;

int n;
struct edge{
	int x,y;
	bool swp;
}e[N];
set<int>s[10][10];
int siz[10][10];
char s1[20],s2[20];
int key[10];
int k;
struct Prufer{
	int n,a[20];
	int e[20][2];
	int ext[20];
	
	void gettree(){
		fo(i,1,n)ext[i]=0;
		fo(i,1,n-2)ext[a[i]]++;
		fo(i,1,n-2){
			int w=0;
			fo(x,1,n)if (ext[x]==0){w=x;break;}
			e[i][0]=a[i];
			e[i][1]=w;
			ext[a[i]]--;
			ext[w]=-1;
		}
		fo(i,1,n)
		if (ext[i]!=-1)
			fo(j,i+1,n)
			if (ext[j]!=-1){
				e[n-1][0]=i;e[n-1][1]=j;
			}
		fo(i,1,n-1)if (e[i][0]>e[i][1])swap(e[i][0],e[i][1]);
	}
}A;
struct Network_Flow{
	int n,st,ed;
	int tot;
	int h[105];
	struct edge{
		int x,f,nxt;
	}e[1005];
	
	void init(int n_,int st_,int ed_){
		n=n_;st=st_;ed=ed_;
		fo(i,1,n)h[i]=0;
		tot=1;
	}
	
	void addedge(int x,int y,int f){e[++tot].x=y;e[tot].f=f;e[tot].nxt=h[x];h[x]=tot;}
	
	void inse(int x,int y,int f){
		addedge(x,y,f);
		addedge(y,x,0);
	}
	
	int que[105];
	int dis[105];
	
	bool bfs(){
		int he=0,ta=1;
		fo(i,1,n)dis[i]=-1;
		que[1]=st;
		dis[st]=0;
		for(;he<ta;){
			int x=que[++he];
			for(int p=h[x];p;p=e[p].nxt)
			if (e[p].f&&dis[e[p].x]==-1){
				dis[e[p].x]=dis[x]+1;
				que[++ta]=e[p].x;
			}
		}
		return dis[ed]!=-1;
	}
	
	int vis[105],tim;
	
	int aug(int x,int f){
		if (x==ed)return f;
		int ret=0;
		for(int p=h[x];p;p=e[p].nxt)
		if (dis[e[p].x]==dis[x]+1&&e[p].f){
			int o=aug(e[p].x,min(f,e[p].f));
			e[p].f-=o,e[p^1].f+=o;
			ret+=o,f-=o;
			if (!f)return ret;
		}
		return ret;
	}
	
	int flow(){
		tim=0;
		fo(i,1,n)vis[i]=0;
		int ret=0;
		while(bfs())ret=ret+aug(st,INF);
		return ret;
	}
}network;
int id[10][10];
int now[10];

void push(int tx,int ty,int x,int y){
	int id=*s[tx][ty].begin();
	s[tx][ty].erase(s[tx][ty].begin());
	e[id].x=x;e[id].y=y;
}

void getans(){
	fo(i,1,k)now[i]=key[i]+1;
	fo(i,1,k-1)push(A.e[i][0],A.e[i][1],key[A.e[i][0]],key[A.e[i][1]]);
	fo(i,1,k)
		fo(j,i,k){
			int w=id[i][j];
			for(int p=network.h[w];p;p=network.e[p].nxt){
				if (network.e[p].x==i)fo(d,1,network.e[p^1].f)push(i,j,now[i]++,key[j]);
				if (network.e[p].x==j&&i!=j)fo(d,1,network.e[p^1].f)push(i,j,key[i],now[j]++);
			}
		}
}

bool Dfs_Prufer(int x){
	if (x>=k-1){
		A.gettree();
		bool pd=1;
		fo(i,1,k-1)pd&=(siz[A.e[i][0]][A.e[i][1]]>0);
		if (!pd)return 0;
		fo(i,1,k-1)siz[A.e[i][0]][A.e[i][1]]--;
		network.init(50,49,50);
		fo(i,1,k)network.inse(i,network.ed,min(key[i+1]-1,n)-key[i]);
		int pre=k;
		fo(i,1,k)
			fo(j,i,k){
				id[i][j]=++pre;
				network.inse(network.st,id[i][j],siz[i][j]);
				network.inse(id[i][j],i,INF);
				if (i!=j)network.inse(id[i][j],j,INF);
			}
		fo(i,1,k-1)siz[A.e[i][0]][A.e[i][1]]++;
		int ret=network.flow();
		if (ret==n-k){
			getans();
			return 1;
		}
		return 0;
	}
	fo(i,1,k){
		A.a[x]=i;
		if(Dfs_Prufer(x+1))return 1;
	}
	return 0;
}

int main(){
	n=get();
	key[1]=1;
	fo(i,2,7)key[i]=key[i-1]*10;
	fo(i,1,n-1){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		e[i].x=strlen(s1+1);
		e[i].y=strlen(s2+1);
		e[i].swp=0;
		if (e[i].x>e[i].y){
			swap(e[i].x,e[i].y);
			e[i].swp=1;
		}
		siz[e[i].x][e[i].y]++;
		s[e[i].x][e[i].y].insert(i);
	}
	fo(i,1,7)if (key[i]<=n)k=i;
	A.n=k;
	if (!Dfs_Prufer(1))return printf("-1\n"),0;
	fo(i,1,n-1){
		if (e[i].swp)swap(e[i].x,e[i].y);
		printf("%d %d\n",e[i].x,e[i].y);
	}
	return 0;
}