#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN];
bool dp[MAXN],ndp[MAXN];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s+=a[i];}
		for(int i=1;i<=n;i++) {scanf("%d",&b[i]); s+=b[i];}
		for(int i=0;i<=s;i++) dp[i]=false;
		dp[0]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=s;j++) ndp[j]=false;
			for(int j=0;j<=s;j++)
			{
				if(j>=a[i]&&dp[j-a[i]]) ndp[j]=true;
				if(j>=b[i]&&dp[j-b[i]]) ndp[j]=true; 
			}
			swap(dp,ndp);
		}

		ll ans=INF,cur=0;
		for(int i=1;i<=n;i++) cur+=1LL*(2*n-4)*a[i]*a[i];
		for(int i=1;i<=n;i++) cur+=1LL*(2*n-4)*b[i]*b[i];	
		for(int i=0;i<=s;i++)
		{
			if(dp[i]) ans=min(ans,1LL*i*i+1LL*(s-i)*(s-i));
		}
		ans=2*ans+cur;
		printf("%lld\n",ans/2);
	}
	return 0;
}