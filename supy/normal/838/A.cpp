#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 2502;
int n,m,a[N][N],sum[N][N],tmp[N],ans=1e9;
//min!!!!!!!!
inline int min(int a, int b) {return((a)<(b)?(a):(b));}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int tot(int a, int b) {
	a = (a>=n) ? n : a;
	b = (b>=m) ? m : b;
	return sum[a][b];
}
inline int query(int k) {
	int res=0;
	for (int i=0; i<=n; i+=k)
		for (int j=0; j<=m; j+=k) {
			int tmp=tot(i+k,j+k)-tot(i,j+k)-tot(i+k,j)+tot(i,j);
			res+=(k*k>=tmp+tmp) ? tmp : k*k-tmp;
		}	
//	printf("%d : %d\n",k,res);
	return res;
}
char ch[N];
int main() {
//	ll ans=0;
//	rep(i,1,2500) ans+=(2500*2500)/i/i;
//	cout<<ans;
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) {
		scanf("%s",ch+1);
		rep(j,1,m) a[i][j]=ch[j]-'0';
	}
	rep(i,1,n) {
		rep(j,1,m) tmp[j]=tmp[j-1]+a[i][j];
		rep(j,1,m) sum[i][j]=sum[i-1][j]+tmp[j];
	}
	rep(i,2,max(n,m)) ans=min(ans,query(i)); //k!!!
	cout<<ans;
	return 0;
}