#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<ll,int>
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

const int N=2005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

priority_queue<pii,vector<pii>,greater<pii> >q;
int n,d[N][N],p;
ll a[N];
bool vis[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	p=1e9;
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			read(d[i][j]);
			d[j][i]=d[i][j];gmin(p,d[i][j]);
		}
	debug(p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) continue;d[i][j]-=p;
			gmin(a[i],(ll)d[i][j]*2);
		}
//	for(int i=1;i<=n;i++) printf("%lld ",a[i]);puts("");
	for(int i=1;i<=n;i++) q.push(mp(a[i],i));
	while(!q.empty()){
		int x=q.top().SS;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
			if(a[i]>a[x]+d[i][x]){
				a[i]=a[x]+d[i][x];
				q.push(mp(a[i],i));
			}
	}
//	for(int i=1;i<=n;i++) printf("%lld ",a[i]);puts("");

	for(int i=1;i<=n;i++) printf("%lld\n",a[i]+(ll)p*(n-1));
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}