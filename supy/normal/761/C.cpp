#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int N = 55;
int n,m,ans=1e9;
int f[N][4]; // num, letter '#'
char s[N][N];


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
const int inf=0x3f3f3f3f;
int main() {
	read(n);read(m);
	rep(i,0,n-1) scanf("%s",s[i]);
	rep(i,0,n-1) rep(j,1,3) f[i][j]=100000;
	rep(i,0,n-1) rep(j,0,m-1)
			if (s[i][j]>='0'&&s[i][j]<='9')
				f[i][1]=min(f[i][1],min(j,m-j));
			else if (s[i][j]>='a'&&s[i][j]<='z')
				f[i][2]=min(f[i][2],min(j,m-j));
			else if (s[i][j]=='#'||s[i][j]=='*'||s[i][j]=='&')
				f[i][3]=min(f[i][3],min(j,m-j));
	rep(i,0,n-1) rep(j,0,n-1) rep(k,0,n-1)
		if (i!=j&&i!=k&&j!=k) {
			ans=min(f[i][1]+f[j][2]+f[k][3],ans);
		}
	cout<<ans;
	return 0;
}