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

const int N=1005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int x,y;}a[N],b[N];
bool operator == (node a,node b){return a.x==b.x&&a.y==b.y;}
int n,k,vis[N],ans;
vi block[10][N];
int calc(int x){
	int ans=0;
	while(x) ans++,x-=x&-x;
	return ans;
}
inline bool line(const node a,const node b,const node c){
//	printf("(%d,%d) (%d,%d) (%d,%d)\n",a.x,a.y,b.x,b.y,c.x,c.y);
//	printf("(%d,%d) (%d,%d)\n",(a.x-b.x),(a.y-c.y),(a.x-c.x),(a.y-b.y));
	if((ll)(a.x-b.x)*(a.y-c.y)!=(ll)(a.x-c.x)*(a.y-b.y)) return 0;
	if(a.x!=b.x) return !((a.x<b.x)^(b.x<c.x));
	return !((a.y<b.y)^(b.y<c.y));
}
bool dfs(int s,vi a){
//	printf("%d && ",s);
//	for(int i=0;i<a.size();i++) printf("%d ",a[i]);puts("");
	if(!a.size()) return 1;
	if(a.size()>calc(s)) return 0;
	for(int i=0;i<k;i++)
		if(s&(1<<i)){
			vi b=a;
			int t=b[b.size()-1];b.pop_back();
			for(int jj=0;jj<block[i][t].size();jj++){
				int j=block[i][t][jj];
				if(!vis[j]) b.pb(j);
				vis[j]++;
			}
			if(dfs(s^(1<<i),b)) return 1;
			for(int jj=0;jj<block[i][t].size();jj++){
				int j=block[i][t][jj];
				vis[j]--;
			}
		}
	return 0;
}
void print(int x,int y){
	printf("block[%d][%d]: %d\n",x,y,block[x][y].size());
	for(int i=0;i<block[x][y].size();i++) printf("%d ",block[x][y][i]);puts("");
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&k,&n);
	for(int i=0;i<k;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++) scanf("%d%d",&b[i].x,&b[i].y);
	for(int i=0;i<k;i++)
		for(int j=1;j<=n;j++)
			for(int l=1;l<=n;l++){
				if(j==l) continue;
				if(line(a[i],b[l],b[j])) block[i][j].pb(l);
				if(block[i][j].size()>k) continue;
			}
//	debug(line(a[1],b[1],b[3]));
//	print(1,3);
	for(int i=1;i<=n;i++){
		vi a;a.clear();
		a.pb(i);clr(vis,0);
		vis[i]=1;
		if(dfs((1<<k)-1,a)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}