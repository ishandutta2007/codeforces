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
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,c0,c1;
ll ans=0;
set<ll> s;
map<ll,ll> f;

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d%d",&n,&c0,&c1);
	n--;
	s.insert(0);
	f[0]=1;
	while(n>0){
		ll x=*s.begin(),p=min((ll)n,f[x]);
		s.erase(s.begin());
//		debug(x);debug(p);
		ans+=(c0+c1+x)*p;
		f[x+c0]+=p;f[x+c1]+=p;
		s.insert(x+c0);s.insert(x+c1);
		n-=p;
	}
	printf("%I64d\n",ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}