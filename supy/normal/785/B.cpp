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
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
int n,m;
#define N 200005
struct L {
	int l,r;
} x[N],y[N];
int l,r,ans;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int main()
{
	read(n); rep(i,1,n) read(x[i].l),read(x[i].r);
	read(m); rep(i,1,m) read(y[i].l),read(y[i].r);
	l=1; r=1;
	rep(i,2,m) {
		if (y[i].l>y[l].l) l=i;
		if (y[i].r<y[r].r) r=i;
	}
	rep(i,1,n) ans=max(ans,max(y[l].l-x[i].r,x[i].l-y[r].r));
	printf("%d",ans);
	return 0;
}