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

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,ans=inf,a,b,w,h,c[N];

void dfs(int x,int w,int h,bool chose){
	if(w>=a&&h>=b){
		gmin(ans,x);
		return;
	}
	if(x==n+1) return;
	if(w<a) dfs(x+1,min((ll)w*c[x],(ll)inf),h,1);
	if(h<b&&(c[x]!=c[x-1]||!chose)) dfs(x+1,w,min((ll)h*c[x],(ll)inf),0);
}

void solve(int aa,int bb){
	a=aa;b=bb;
	sort(c+1,c+n+1);
	reverse(c+1,c+n+1);
	dfs(1,1,1,0);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	int a,b;
	scanf("%d%d%d%d%d",&a,&b,&w,&h,&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	solve((a+w-1)/w,(b+h-1)/h);
	solve((a+h-1)/h,(b+w-1)/w);
	printf("%d\n",ans<inf?ans-1:-1);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}