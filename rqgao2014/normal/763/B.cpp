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

const int N=1000005,M=100005,mod=1e9+7;
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

bool check(int x,int y,int l,int r){return min(y,r)>max(x,l);}
struct node{int x1,x2,y1,y2;}a[N];
int n,sx,sy,xx[N],yy[N],c[N],du[N],b[N];
vi up[N],down[N],weak[N],strong[N],g[N];
bool vis[N];
queue<int> q;

inline void add(int x,int y){
//	printf("%d %d\n",x,y);
	du[x]++;du[y]++;
	g[x].pb(y);g[y].pb(x);
}
inline bool cmp2(int x,int y){return a[x].x1<a[y].x1;}
inline bool cmp1(int x,int y){return a[x].y1<a[y].y1;}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
#endif
	ios::sync_with_stdio(0);
	puts("YES");
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].x1),read(a[i].y1);
		read(a[i].x2),read(a[i].y2);
		xx[++sx]=a[i].x1,xx[++sx]=a[i].x2;
		yy[++sy]=a[i].y1,yy[++sy]=a[i].y2;
	}
	sort(xx+1,xx+sx+1);
	sort(yy+1,yy+sy+1);
	sx=unique(xx+1,xx+sx+1)-xx-1;
	sy=unique(yy+1,yy+sy+1)-yy-1;
//	for(int i=1;i<=sx;i++) printf("%d ",xx[i]);puts("");
//	for(int i=1;i<=sy;i++) printf("%d ",yy[i]);puts("");
	for(int i=1;i<=n;i++){
		a[i].x1=lower_bound(xx+1,xx+sx+1,a[i].x1)-xx;
		a[i].x2=lower_bound(xx+1,xx+sx+1,a[i].x2)-xx;
		a[i].y1=lower_bound(yy+1,yy+sy+1,a[i].y1)-yy;
		a[i].y2=lower_bound(yy+1,yy+sy+1,a[i].y2)-yy;
		up[a[i].x2].pb(i);down[a[i].x1].pb(i);
		strong[a[i].y2].pb(i);weak[a[i].y1].pb(i);
	}
	for(int i=1;i<=sx;i++){
		int l=0,r=0,sl=up[i].size(),sr=down[i].size();
		if(!sl||!sr) continue;
		sort(up[i].begin(),up[i].end(),cmp1);
		sort(down[i].begin(),down[i].end(),cmp1);
		while(l<sl&&r<sr){
			int x=up[i][l],y=down[i][r];
			if(check(a[x].y1,a[x].y2,a[y].y1,a[y].y2)) add(x,y);
			if(a[x].y2<a[y].y2) l++; else r++;
		}
	}
	for(int i=1;i<=sy;i++){
		int l=0,r=0,sl=weak[i].size(),sr=strong[i].size();
		sort(weak[i].begin(),weak[i].end(),cmp2);
		sort(strong[i].begin(),strong[i].end(),cmp2);
//		if(i==5){
//			for(int j=0;j<weak[i].size();j++) printf("%d ",weak[i][j]);puts("");
//			for(int j:strong[i]) printf("%d ",j);puts("");
//		}
		while(l<sl&&r<sr){
			int x=weak[i][l],y=strong[i][r];
//			if(x==4&&y==5) debuge;
			if(check(a[x].x1,a[x].x2,a[y].x1,a[y].x2)) add(x,y);
			if(a[x].x2<a[y].x2) l++; else r++;
		}
	}
	for(int i=1;i<=n;i++)
		if(du[i]<4) q.push(i),vis[i]=1;
	for(int i=n;i;i--){
		int x=q.front();q.pop();
		b[i]=x;
		for(int y:g[x])
			if(!vis[y]){
				du[y]--;
				if(du[y]<4) q.push(y),vis[y]=1;
			}
	}
	for(int i=1;i<=n;i++){
		int x=b[i];
		for(int j=1;j<=4;j++) vis[j]=0;
		for(int y:g[x])
			vis[c[y]]=1;
		c[x]=1;
		while(vis[c[x]]) c[x]++;
	}
	for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}