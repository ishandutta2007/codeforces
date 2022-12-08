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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=105,M=500005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct edge{int to,next,v;};
class max_flow{
	private:
	edge p[M];
	int S,T,head[N],st[N],tot,res;
	queue<int> q;
	bool bfs(int x){
		memset(st,0,sizeof(st));
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
	public:
	void dinic(){
		int t;
		while(bfs(S))
			while(t=dfs(S,inf)) res-=t;
	}
	void add(int x,int y,int z){
		p[tot].to=y;p[tot].next=head[x];p[tot].v=z;head[x]=tot++;
		p[tot].to=x;p[tot].next=head[y];p[tot].v=0;head[y]=tot++;
		if(z<inf) res+=z;
	}
	void build(int s,int t){S=s;T=t;}
	void clear(){
		memset(head,-1,sizeof(head));
		tot=0;
	}
	int get(){return res;}
}xhk;

struct node{int p,c,l;}p[N];
int n,m,K,S,T,a[N],mx;
bool check(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return 1;
	return 0;
}

bool cmp(node a,node b){return a.l<b.l;}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	xhk.clear();
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].p,&p[i].c,&p[i].l),a[i]=p[i].c;
	sort(p+1,p+n+1,cmp);
	sort(a+1,a+n+1);
	m=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=m;i++){
		if(a[i]%2==0) continue;
		for(int j=1;j<=m;j++)
			if(a[j]%2==0&&!check(a[i]+a[j])) xhk.add(i,j,inf);
	}
//	debug(xhk.get());
	S=0;T=m+1;
	xhk.build(S,T);
	for(int i=1;i<=n;i++){
		int k=p[i].c,lab=lower_bound(a+1,a+m+1,k)-a;
		if(k==1){
			if(p[i].p>mx) xhk.add(S,lab,p[i].p-mx),mx=p[i].p;
		}else if(k&1) xhk.add(S,lab,p[i].p);
		else xhk.add(lab,T,p[i].p);
		xhk.dinic();
//		debug(xhk.get());
		if(xhk.get()>=K){printf("%d\n",p[i].l);goto the_hell;}
	}
	puts("-1");
#ifdef rqgao2014
	time_tester(1);
#endif
	the_hell:return 0;
}