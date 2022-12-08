#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define fore(i,x,k) for(int i=head[x],y=p[i].to;i!=k;i=p[i].next,y=p[i].to)
#define rep(i,x,y) for(int i=x;i<=y;i++)
namespace fastio{
	inline bool read(int &x){
		x=0;char ch=getchar(),flag=0;
		while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
		if(ch=='-') flag=1,ch=getchar();
		if(ch>'9'||ch<'0') return 0;
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(flag) x=-x;
		return 1;
	}
	inline bool read(int &x,int &y){return (read(x)&&read(y));}
	inline bool read(int &x,int &y,int &z){return (read(x)&&read(y)&&read(z));}
	inline void _put(int x){
		if(!x){putchar('0');return;}
		int a[20],m=0;
		while(x) a[m++]=x%10,x/=10;
		while(m--) putchar(a[m]+'0');
	}
	inline void print(int x){_put(x);puts("");}
	inline void print(int x,int y){_put(x);putchar(' ');_put(y);puts("");}
	inline void print(int x,int y,int z){_put(x);putchar(' ');_put(y);putchar(' ');_put(z);puts("");}
	inline void _print(int x){_put(x);putchar(' ');}
	inline void _print(int x,int y){_print(x);_print(y);}
	inline void _print(int x,int y,int z){_print(x,y);_print(z);}
};
namespace counter{
	int x=0;
	inline int CASE(){printf("Case %d: ",++x);}
	inline int CASE2(){printf("Case #%d: ",++x);}
};
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
using namespace fastio;

const int N=100005;
struct node{
	int to,next,w;
}p[N<<2];
int tot,head[N],n,m,si,id;
ll ans;
bool vis[N];
inline void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
}
inline int getroot(int x,int fa){
	int tmp=1,maxx=0;
	fore(i,x,0){
		if(y==fa||vis[y]) continue;
		int t=getroot(y,x);
		maxx=max(t,maxx);tmp+=t;
	}
	maxx=max(si-tmp,maxx);
	if(maxx<=si/2) id=x;
	return tmp;
}
inline int getsize(int x,int fa){
	int tmp=1;
	fore(i,x,0){
		if(y==fa||vis[y]) continue;
		tmp+=getsize(y,x);
	}
	return tmp;
}
vector<pii> a,b;
map<int,int> sa,sb;
inline void solve(int x,int fa,int aa,int bb,int k){
	k=(ll)k*10%m;
	a.pb(mp(aa,k));b.pb(mp(bb,k));
	fore(i,x,0){
		if(vis[y]||y==fa) continue;
		solve(y,x,((ll)aa*10+p[i].w)%m,((ll)k*p[i].w+bb)%m,k);
	}
}
inline void gcd(ll x,ll y,ll &a,ll &b){
	if(!y){a=1;b=0;return;}
	ll ta,tb;
	gcd(y,x%y,ta,tb);
	a=tb;b=(ta-x/y*tb);
//	printf("%d %d %I64d %I64d\n",x,y,a,b);
}
inline int inv(int x){
	ll a,b;
	gcd(x,m,a,b);
	a=(a%m+m)%m;
//	printf("%d %d\n",x,a);
	return (int)a;
}
inline void dfs(int x){
	sa.clear();sb.clear();
//	printf("Task:%d\n",x);
	fore(i,x,0){
		if(vis[y]) continue;
//		printf("%d\n",y);
		a.clear();b.clear();
		solve(y,x,p[i].w%m,p[i].w%m,1);
		rep(j,0,a.size()-1) ans+=sa[(ll)a[j].FF*inv(a[j].SS)%m];
		rep(j,0,a.size()-1) ans+=sb[(m-b[j].FF)%m];
		rep(j,0,a.size()-1) ans+=(!a[j].FF)+(!b[j].FF);
//		puts("");
		rep(j,0,a.size()-1) sa[(m-b[j].FF)%m]++;
		rep(j,0,a.size()-1) sb[(ll)a[j].FF*inv(a[j].SS)%m]++;
	}
//	printf("%I64d\n",ans);
	vis[x]=1;
	fore(i,x,0){
		if(vis[y]) continue;
		si=getsize(y,x);getroot(y,x);
		dfs(id);
	}
}

int main(){
	read(n,m);
//	printf("%d\n",inv(10));
	rep(i,1,n-1){
		int x,y,z;
		read(x,y,z);x++;y++;
		add(x,y,z);
	}
	dfs(1);
	printf("%I64d\n",ans);
	return 0;
}