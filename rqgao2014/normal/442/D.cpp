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

int n,fa[N],mx[N],dp[N],cnt[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n);
	for(int i=2;i<=n+1;i++){
		read(fa[i]);
		int x=i;
		while(x){
			int y=fa[x];
			if(mx[y]>dp[x]) break;
			else if(mx[y]==dp[x]){
				cnt[y]++;
				if(cnt[y]!=2) break;
			}
			else if(mx[y]<dp[x]){
				mx[y]=dp[x];cnt[y]=1;
				if(dp[y]==mx[y]) break;
			}
			dp[y]++;x=y;
		}
		printf("%d%c",mx[1]+1,i<=n?' ':'\n');
	}
	return 0;
}