#include<bits/stdc++.h>
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
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int mod=1e9+7,N=100005,M=1505;
int n,m,a,b,k,P,f[N],g[N];
int dp[M],sp[M],s[M],sum[M],p[M];

inline int exp(int x,int y){
	if(y<0) return 0;
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
inline int C(int x,int y){
	if(x<y) return 0;
	return (ll)f[x]*g[y]%mod*g[x-y]%mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	n=100000;f[0]=1;
	for(int i=1;i<=n;i++) f[i]=(ll)f[i-1]*i%mod;
	g[n]=exp(f[n],mod-2);
	for(int i=n-1;~i;i--) g[i]=(ll)g[i+1]*(i+1)%mod;
	read(m,n);
	read(a,b,k);
	P=(ll)a*exp(b,mod-2)%mod;
	for(int i=0;i<=n&&i<=k;i++) p[i]=(ll)C(k,i)*exp(P,i)%mod*exp((mod+1-P)%mod,k-i)%mod;//,printf("%d ",p[i]);puts("");
	sp[0]=p[0];
	for(int i=1;i<=n;i++) sp[i]=(sp[i-1]+p[i])%mod;
	dp[n]=1;
	for(int i=1;i<=m;i++){
		sum[0]=0;
		for(int j=1;j<=n;j++)
			sum[j]=(sum[j-1]+dp[j])%mod;
//		printf("%d %d\n",sum[n],3ll*exp(4,mod-2)%mod);
		s[0]=0;
		for(int j=1;j<=n;j++)
			s[j]=((ll)sum[j]*p[j]%mod+s[j-1])%mod;
		for(int j=1;j<=n;j++){
//			printf("%d ",s[j-1]);
			dp[j]=(ll)((ll)sp[j-1]*(sum[n]-sum[n-j]+mod)-s[j-1]+mod)%mod*p[n-j]%mod;
		}
//		for(int j=1;j<=n;j++)
//			printf("%d ",dp[j]);
//		puts("");
	}
	int ans=0;
	for(int j=1;j<=n;j++)
		ans=(ans+dp[j])%mod;
	printf("%d\n",ans);
	return 0;
}
/*

2 2
1 2
1
*/