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
using namespace std;

const int N=1000005,M=100005,mod=1e9+7,G=1000000;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

int n,a[N],sum[N],s[N],pw[10],cnt[N],g[N],pw2[N];

int main(){
	pw[0]=pw2[0]=1;for(int i=1;i<=6;i++) pw[i]=pw[i-1]*10;
	for(int i=1;i<=G;i++) pw2[i]=pw2[i-1]*2%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ch(s[G-1-x],x);
		ch(sum[G-1-x],(ll)x*x%mod);
		cnt[G-1-x]++;
	}
	for(int i=0;i<6;i++)
		for(int j=0;j<G;j++)
			if((j/pw[i])%10) 
				ch(s[j],s[j-pw[i]]),ch(sum[j],sum[j-pw[i]]),cnt[j]+=cnt[j-pw[i]];
	for(int i=0;i<G;i++){
		if(cnt[i]==1) g[i]=(ll)s[i]*s[i]%mod; 
		else g[i]=((ll)sum[i]+(ll)s[i]*s[i]%mod)*pw2[cnt[i]-2]%mod;
//		if(cnt[i]>1) debuge;
	}
	for(int i=0;i<6;i++)
		for(int j=G-1;j;j--)
			if((j/pw[i])%10) 
				ch(g[j],mod-g[j-pw[i]]);
	ll ans=0;
//	debug(cnt[0]);
	for(int i=0;i<1000000;i++){
//		if(g[i]>0) debug(i);
		ans^=(ll)g[i]*(G-1-i);
	}
	cout<<ans<<endl;
	return 0;
}