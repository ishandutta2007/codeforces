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

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
template<class T> inline void read(T &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
template<class T> inline void print(T x){
	if(!x){puts("0");return;}
	if(x<0){putchar('-');x=-x;}
	int a[20],m=0;
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');puts("");
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int to,next;}p[N<<1];
int n,tot,root,c[N],head[N];
bool vis[N];
inline void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;
}
bool dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		if(dfs(y)) return 1;
		if(x!=root&&c[x]!=c[y]){root=x;return 1;}
	}
	return 0;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
#endif
	ios::sync_with_stdio(0);
	read(n);
	for(int i=1;i<n;i++){
		int x,y;read(x);read(y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		read(c[i]);
	root=1;
	if(dfs(1)){
		clr(vis,0);
		if(dfs(root)){puts("NO");return 0;}
	}
	printf("YES\n%d\n",root);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}