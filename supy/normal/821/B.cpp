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
const int N = 10005;
int m,b;
ll ans;
ll getS(int x, int y) {
	ll a=(ll)x*(x+1)/2*(y+1),b=(ll)y*(y+1)/2*(x+1);
	return a+b;
}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(m);read(b);
	rep(i,0,b) {
		int x=m*(b-i);
		ans=max(ans,getS(x,i));
	//	printf("%d %d %lld\n",x,i,ans);
	}
	printf("%lld",ans);
	return 0;
}