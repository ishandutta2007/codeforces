#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 200005
ll ans;
int s[N];
int n,k,a[N],b[N],x1[N],x2[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(k);
	rep(i,1,n) {read(a[i]);read(b[i]);}
	rep(i,1,n) {
		x1[i]=min(a[i],b[i]);
		x2[i]=min(a[i]*2,b[i]);
		ans+=x1[i]; s[i]=x2[i]-x1[i];
	}
	sort(s+1,s+n+1);
	rep(i,1,k) ans+=s[n-i+1];
	printf("%lld\n",ans);
	return 0;
}