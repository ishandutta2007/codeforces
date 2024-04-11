#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 100005
int n,a[N],x[N];
ll ans,f[N];

inline int abs(int x){return x>0?x:-x;}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void getans(int p) {
	f[p]=x[p]; ans=max(ans,f[p]);
	for (int i=p-2; i>=1; i-=2) {
		f[i]=max(x[i],x[i]-x[i+1]+f[i+2]);
		ans=max(ans,f[i]);
	}
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n-1) x[i]=abs(a[i+1]-a[i]); n--;
	getans(n); getans(n-1);
	printf("%lld",ans);
	return 0;
}