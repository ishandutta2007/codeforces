#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 100005
typedef long double ld;
int n;
int x[N],v[N];
ld a,b,ans=1e10;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
void get(ld k) {
	a=b=0;
	rep(i,1,n) {
		if (x[i]<k) a=max(a,(k-x[i])/v[i]);
		else b=max(b,(x[i]-k)/v[i]);
	}
}
int main()
{
	read(n);
	rep(i,1,n) read(x[i]);
	rep(i,1,n) read(v[i]);
	ld l=1,r=0; rep(i,1,n) r=max(r,x[i]); r+=1e-6;
	rep(i,1,100) {
		ld mid=(l+r)/2;
		get(mid);
		ans=min(ans,max(a,b));
		if (a>b) r=mid;
		else l=mid;
	}
	printf("%.12lf",(double)ans);
	return 0;
}