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
#define inf 2000000007
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=5005,M=20005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,flow,cost;}p[M];
int n,k,S,T,tot,head[N],d[N],ans,last[N],path;
bool vis[N];
queue<int> q;
void add(int x,int y,int f,int c){
//	printf("%d %d %d %d\n",x,y,f,c);
	p[++tot]=(node){y,head[x],f,c};head[x]=tot;
	p[++tot]=(node){x,head[y],0,-c};head[y]=tot;
}
int dfs(int x,int f){
	if(x==T) return f;
	vis[x]=1;
	int r=f;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,tmp;
		if(p[i].cost||!p[i].flow||vis[y]) continue;
		tmp=dfs(y,min(r,p[i].flow));
		p[i].flow-=tmp;p[i^1].flow+=tmp;
		r-=tmp;
		if(!r) return f;
	}
	return f-r;
}
bool modlabel(){
	int d=inf;
	for(int i=S;i<=T;i++){
		if(!vis[i]) continue;
		for(int j=head[i];j;j=p[j].next)
			if(p[j].flow&&!vis[p[j].to]) d=min(d,p[j].cost);
	}
	if(d>=inf) return 0;
	for(int i=S;i<=T;i++){
		if(!vis[i]) continue;
		for(int j=head[i];j;j=p[j].next)
			p[j].cost-=d,p[j^1].cost+=d;
	}
	path+=d;
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	tot=1;
	scanf("%d%d",&n,&k);
	S=0;T=n*2+1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		add(S,i,1,x);
		add(i,i+n,inf,0);
	}
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		add(i+n,T,1,x);
		if(i<n) add(i+n,i+n+1,inf,0);
	}
	int cap=0;
	ll ans=0;
	do{
		clr(vis,0);
		int t=0;
		while(t=dfs(S,inf)) ans+=(ll)path*t,cap+=t,clr(vis,0);
		if(cap>=k){
			ans-=(ll)path*(cap-k);
			break;
		}
	}while(modlabel());
	cout<<ans<<endl;
	return 0;
}