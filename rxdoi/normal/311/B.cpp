//CF311B
#include <bits/stdc++.h>
#define y1 y1_
#define index index_
#define pipe pipe_
#define next next_
#define rgi register int
#define ll long long
#define Pi acos(-1.0)
#define lowbit(x) ((x&(-x)))
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
inline int read() {
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1e5+5;
const ll INF=1e18;
ll n,m,p,d[MAXN],a[MAXN],s[MAXN],q[MAXN],dp[105][MAXN];
double xl(int i,int j,int jj) {
	if(jj==j) return -INF;
	return 1.0*((dp[i-1][jj]+s[jj])-(dp[i-1][j]+s[j]))/(jj-j);
}
int main() {
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);/*syn*/
	n=read();m=read();p=read();
	for(rgi i=2;i<=n;++i) d[i]=read()+d[i-1];
	for(rgi i=1;i<=m;++i) {
		int h=read(),t=read();
		a[i]=t-d[h]; s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+m+1);
	memset(dp,0x3f,sizeof(dp)); dp[0][0]=0;
	for(rgi i=1;i<=p;++i) {
		int l=1,r=1; q[r]=0;
		for(rgi j=1;j<=m;++j) {
			while(l<r && xl(i,q[l],q[l+1])<=a[j]) l++;
			int k=q[l];
			dp[i][j]=min(dp[i-1][j],dp[i-1][k]+a[j]*(j-k)-(s[j]-s[k]));
			
			if(dp[i-1][j]+s[j]>INF) continue;
			while(l<r && xl(i,q[r-1],q[r])>=xl(i,q[r],j)) r--;
			q[++r]=j;
		}
	}
	cout<<dp[p][m]<<endl;
	return 0;
}