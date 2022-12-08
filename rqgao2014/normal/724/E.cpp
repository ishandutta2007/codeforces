#include<bits/stdc++.h>
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
using namespace std;

const int N=10005;
const ll inf=1ll<<60;
int n,c,p[N],s[N];
ll ans,dp[2][N];

int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	ll tmp=0;
	for(int i=1;i<=n;i++)
		if(p[i]>=s[i]) p[i]-=s[i],tmp+=s[i],s[i]=0; else s[i]-=p[i],tmp+=p[i],p[i]=0;
	int k=0;
	for(int i=0;i<2;i++) for(int j=0;j<=n;j++) dp[i][j]=inf;
	dp[k][0]=0;
	for(int i=1;i<=n+1;i++){
		k^=1;
		for(int j=0;j<=i;j++) dp[k][j]=inf;
		for(int j=0;j<i;j++){
			if(p[i]) dp[k][j]=min(dp[k^1][j]+(ll)j*c+p[i],dp[k][j]); else dp[k][j]=min(dp[k^1][j]+(ll)j*c,dp[k][j]);
			if(s[i]) dp[k][j+1]=min(dp[k^1][j]+s[i],dp[k][j+1]); else dp[k][j+1]=min(dp[k^1][j],dp[k][j+1]);
		}
	}
	ll ans=inf;
	for(int j=0;j<=n+1;j++) ans=min(ans,dp[k][j]);
	printf("%I64d\n",ans+tmp);
	return 0;
}