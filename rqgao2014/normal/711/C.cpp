#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
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
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
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

const int N=105;
const ll inf=1ll<<50;
int n,m,c,a[N],p[N][N];
ll dp[2][N][N],mx[N],mx2[N];

inline void upt(ll &mx,ll &mx2,ll y){
	if(y<mx) mx2=mx, mx=y;
	else if(y<mx2) mx2=y;
}
inline ll get(ll mx,ll mx2,ll y){
	if(y==mx) return mx2;
	return mx;
}

int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&p[i][j]);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[0][i][j]=inf;
	dp[0][0][0]=0;
	int d=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			mx[j]=mx2[j]=inf;
			for(int k=0;k<=m;k++)
				upt(mx[j],mx2[j],dp[d][j][k]);
		}
		d^=1;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m;k++)
				dp[d][j][k]=inf;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++){
				if(!a[i]){
					dp[d][j][k]=min(dp[d][j][k],dp[d^1][j][k]+p[i][k]);
					dp[d][j][k]=min(dp[d][j][k],get(mx[j-1],mx2[j-1],dp[d^1][j-1][k])+p[i][k]);
				}
				else if(k==a[i]){
					dp[d][j][k]=min(dp[d][j][k],dp[d^1][j][k]);
					dp[d][j][k]=min(dp[d][j][k],get(mx[j-1],mx2[j-1],dp[d^1][j-1][k]));
				}
			}
	}
	ll ans=inf;
	for(int j=1;j<=m;j++)
		ans=min(ans,dp[d][c][j]);
	if(ans<inf) cout<<ans<<endl; else puts("-1");
	return 0;
}