#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int mod = 1e9+7;
int dp[32][2][2][2],g[32][2][2][2];
inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
inline int calc(int l,int r,int k){
	if (l<0||r<0) return 0;
	fil(dp,0),fil(g,0);
	dp[31][1][1][1]=1;
	Dow(i,30,0){
		int a=(l>>i&1),b=(r>>i&1),c=(k>>i&1);
		For(j,0,1) For(k,0,1) For(l,0,1){
			For(x,0,j?a:1) For(y,0,k?b:1){
				if (l==0){
					upd(dp[i][j&&x==a][k&&y==b][l],dp[i+1][j][k][l]);
					upd(g[i][j&&x==a][k&&y==b][l],(g[i+1][j][k][l]+1ll*dp[i+1][j][k][l]*((x^y)<<i))%mod);
				} else if ((x^y)<=c){
					upd(dp[i][j&&x==a][k&&y==b][l&&((x^y)==c)],dp[i+1][j][k][l]);
					upd(g[i][j&&x==a][k&&y==b][l&&((x^y)==c)],(g[i+1][j][k][l]+1ll*dp[i+1][j][k][l]*((x^y)<<i))%mod);
				}
			}
		}
	}
	int ans=0;
	For(i,0,1) For(j,0,1) For(k,0,1) upd(ans,dp[0][i][j][k]),upd(ans,g[0][i][j][k]);
	return ans;
}
inline void solve(){
	int x1=read()-1,y1=read()-1,x2=read()-1,y2=read()-1,k=read()-1;
	int ans=calc(x2,y2,k);
	ans=(ans+calc(x1-1,y1-1,k))%mod;
	ans=(ans+mod-calc(x1-1,y2,k))%mod;
	ans=(ans+mod-calc(x2,y1-1,k))%mod;
	printf("%d\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}