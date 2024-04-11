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
#define N 10004
int n,m;
int p[N];
int l,r,x;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
inline bool judge() {
	/*if (x<l||x>r) return 1;
	if ((r-l+1)%2==1&&x==((l+r)>>1)) return 1;
	return 0;*/
	int cnt=0;
	rep(i,l,r) cnt+=(p[i]<=p[x]);
	return (l+cnt-1==x);
}
int main()
{
	read(n); read(m);
	rep(i,1,n) read(p[i]);
	rep(i,1,m) {
		read(l);read(r);read(x);
		if (judge()) puts("Yes");
		else puts("No");
	}
	return 0;
}