#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 300005
#define mo 1000000007
int n,x[N];
ll Pre[N],ans,Bit[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) read(x[i]);
	sort(x+1,x+n+1);
	rep(i,1,n) Pre[i]=(Pre[i-1]+x[i])%mo;
	Bit[0]=1; rep(i,1,n) Bit[i]=Bit[i-1]*2%mo;
	rep(i,1,n-1) {
		ll tmp=(Pre[n]-Pre[i]-Pre[n-i]+mo+mo)%mo;
		ans+=tmp*Bit[i-1]%mo;
		ans%=mo;
	}
	printf("%d",ans);
	return 0;
}