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
#define min(a,b) ((a)<(b)?(a):(b))
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
const int mo = 998244353;
int a,b,c;
int f[5002][5002];
ll ans;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline ll calc(int a, int b) {
	/*if (a>b) swap(a,b); //a<=b
	ll res=1;
	rep(i,b-a+1,b) res=res*i%mo;
	return res;*/
	return f[a][b];
}
int main() {
	rep(i,1,5000) f[i][1]=f[1][i]=i+1;
	rep(i,2,5000) rep(j,2,5000) 
		f[i][j]=((ll)f[i-1][j]+(ll)j*f[i-1][j-1])%mo;
	read(a);read(b);read(c);
	printf("%d",(ll)calc(a,b)*calc(a,c)%mo*calc(b,c)%mo);
	return 0;
}