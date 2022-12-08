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

const int N=50005,M=1000005,mod=1e9+7;
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

int n,m,tot,b[N],a[M][2],si[M],cnt[M][30];

int check(int mid){
	ui cnt=0;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=29;~j;j--){
			int c=(b[i]>>j)&1;
			if(mid&(1<<j)) k=a[k][c^1];
			else cnt+=si[a[k][c^1]],k=a[k][c];
			if(!k) break;
		}
		if(k) cnt+=si[k];
	}
	return cnt/2;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		int k=0;
		for(int j=29;~j;j--){
			int c=(b[i]>>j)&1;
			if(!a[k][c]) a[k][c]=++tot;
			k=a[k][c];si[k]++;
			for(int t=0;t<j;t++)
				if(b[i]&(1<<t)) cnt[k][t]++;
		}
	}
	int l=0,r=(1<<30)-1;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)>=m) l=mid; else r=mid-1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int k=0,res=0;
		for(int j=29;~j;j--){
			int c=(b[i]>>j)&1;
			if(r&(1<<j)) k=a[k][c^1];
			else{
				int t=a[k][c^1];k=a[k][c];
				ch(res,(ll)si[t]*((r>>j|1)<<j)%mod);
//				if(i==2&&j==1) debug(res);
				for(int p=0;p<j;p++)
					if(b[i]&(1<<p)) ch(res,((ll)(si[t]-cnt[t][p])<<p)%mod);
					else ch(res,((ll)cnt[t][p]<<p)%mod);
			}
			if(!k) break;
		}
//		debug(res);
		if(k) ch(res,(ll)si[k]*r%mod);
//		debug(res);
		ch(ans,res);
	}
//	debug(ans);
	ans=(ll)ans*exp(2,mod-2)%mod;
	ch(ans,mod-(ll)(check(r)-m)*r%mod);
	printf("%d\n",ans);
	return 0;
}