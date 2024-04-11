#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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

const int N = 1e5+10;
int n,a[2][N];
ll dp[N][3];

int main(){
	n=read();
	For(i,1,n) a[0][i]=read();
	For(i,1,n) a[1][i]=read();
	For(i,0,n) For(j,0,2) dp[i][j]=-1e15;
	dp[0][0]=0;
	For(i,1,n){
		dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
		dp[i][1]=max({dp[i-1][0],dp[i-1][2]})+a[0][i];
		dp[i][2]=max({dp[i-1][0],dp[i-1][1]})+a[1][i];
	}
	ll ans=max({dp[n][0],dp[n][1],dp[n][2]});
	printf("%lld\n",ans);
}