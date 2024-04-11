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
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=1005,M=200005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,flow,cost;}p[M];
int n,m,S,T,tot,head[N],d[N],ans;
bool vis[N];
queue<int> q;
void add(int x,int y,int f,int c){
//	if(c<0) printf("%d %d %d\n",x,y,c);
	p[++tot]=(node){y,head[x],f,c};head[x]=tot;
	p[++tot]=(node){x,head[y],0,-c};head[y]=tot;
}
bool spfa(){
	clr(vis,0);
	for(int i=0;i<=n+1;i++) d[i]=inf;
	q.push(S);vis[S]=1;d[S]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(!p[i].flow) continue;
			if(d[y]>d[x]+p[i].cost){
				d[y]=d[x]+p[i].cost;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
	return d[T]<inf;
}
int dfs(int x,int f){
	if(x==T) return f;
	vis[x]=1;int r=f;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,tmp;
		if(vis[y]||!p[i].flow||d[y]!=d[x]+p[i].cost) continue;
		tmp=dfs(y,min(r,p[i].flow));
		p[i^1].flow+=tmp;p[i].flow-=tmp;
		r-=tmp;if(!r) break;
	}
	return f-r;
}

char s[N],str[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	int x;
	scanf("%d%s%d",&n,s+1,&m);
	S=0,T=n+1;tot=1;
	for(int i=1;i<=m;i++){
		int l,p;
		scanf("%s%d",str+1,&p);
		l=strlen(str+1);
		for(int j=1;j<=n-l+1;j++){
			bool isok=1;
			for(int k=1;k<=l;k++)
				if(s[j+k-1]!=str[k]){isok=0;break;}
			if(isok)add(j,j+l,1,-p);
		}
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i++)
		add(i,i+1,inf,0);
	add(S,1,x,0);
	while(spfa()){
//		debug(d[T]);
		if(d[T]>0) break;
		int t=0;while(t=dfs(S,inf)) ans+=d[T]*t,clr(vis,0);
	}
	printf("%d\n",-ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}