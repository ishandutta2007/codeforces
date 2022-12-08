#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=105,M=1005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,v;}p[M];
int n,m,e[N][N],num[N][N],cnt[N],root[N],from[N];
//vi g[N][N];
int S,T,head[N],st[N],tot;
queue<int> q;
bool bfs(int x){
	clr(st,0);
	st[x]=1;q.push(x);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];~i;i=p[i].next){
			int y=p[i].to,v=p[i].v;
			if(!v||st[y]) continue;
			st[y]=st[x]+1;q.push(y);
		}
	}
	return st[T]>0;
}
int dfs(int x,int f){
	int r=0;
	if(x==T) return f;
	for(int i=head[x];~i;i=p[i].next){
		int y=p[i].to,v=p[i].v,tmp;
		if(!v||st[y]!=st[x]+1) continue;
		tmp=dfs(y,min(f-r,v));
		r+=tmp;
		p[i].v-=tmp;p[i^1].v+=tmp;
		if(r==f)break;
	}
	if(!r) st[x]=-1;
	return r;
}
int dinic(){
	int ans=0,t;
	while(bfs(S))
		while(t=dfs(S,inf)) ans+=t;
	return ans;
}
void add(int x,int y,int z){
//	printf("%d %d %d\n",x,y,z);
	p[tot]=(node){y,head[x],z};head[x]=tot++;
	p[tot]=(node){x,head[y],0};head[y]=tot++;
}
void clear(){
	memset(head,-1,sizeof(head));tot=0;
}
int fa[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool check(){
	for(int i=1;i<=m;i++)
		fa[i]=i;
	for(int i=2;i<=m;i++)
		fa[find(i)]=find(from[i]);
	for(int i=1;i<=m;i++)
		if(find(i)!=find(1)) return 0;
	return 1;
}

void dfs(int x){
	if(x==m+1){
		if(!check()) return;
		clear();
		S=0,T=100;
		for(int i=1;i<=m;i++)
			add(S,i,cnt[i]-1);
		for(int i=1;i<=m;i++)
			for(int j=i;j<=m;j++){
//				printf("%d ",e[i][j]);
				add(num[i][j],T,e[i][j]);
				add(i,num[i][j],inf);
				add(j,num[i][j],inf);
			}
		int tmp=dinic()+m;
		if(tmp==n){
			for(int i=2;i<=m;i++){
//				int k=pop(from[i],i);
				printf("%d %d\n",root[i],root[from[i]]);
//				v[k]=root[i];u[k]=root[from[i]];
			}
			for(int i=1;i<=m;i++){
				int cnt=root[i];
				for(int l=1;l<=m;l++)
					for(int r=l;r<=m;r++){
						if(l!=i&&r!=i) continue;
//						printf("%d %d %d\n",i,l,r);
						int nei=(l!=i?l:r);
//						debug(nei);
						for(int j=head[i];~j;j=p[j].next){
							int y=p[j].to;
							if(y!=num[l][r]) continue;
							for(int k=1;k<=p[j^1].v;k++){
//								int h=pop(l,r);
								printf("%d %d\n",++cnt,root[nei]);
//								u[h]=++cnt;v[h]=root[nei];
							}
						}
					}
			}
			/*for(int i=1;i<n;i++){
				if(u[i]>v[i]) swap(u[i],v[i]);
				if(rev[i]) printf("%d %d\n",v[i],u[i]); else printf("%d %d\n",u[i],v[i]);
			}*/
			exit(0);
		}
		return ;
	}
	for(int i=1;i<=m;i++){
		if(i==x||(!e[i][x]&&!e[x][i])) continue;
		if(i<x)e[i][x]--;else e[x][i]--;from[x]=i;
		dfs(x+1);
		if(i<x) e[i][x]++;else e[x][i]++;
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		char x[10],y[10];
		int l,r;
		scanf("%s%s",x,y);
		l=strlen(x);r=strlen(y);
		if(l>r) swap(l,r);
		e[l][r]++;
	}
	for(int i=1,t=n,now=9;t;m=i,i++,now*=10){
		cnt[i]=min(now,t);t-=min(now,t);
		root[i]=now/9;
	}
	tot=m;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			num[i][j]=++tot;
	dfs(2);
	puts("-1");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}