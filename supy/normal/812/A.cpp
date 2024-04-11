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
int l[6],s[6],r[6],p[6];
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int M(int x) {int res=x%4; if (res==0) res=4; return res;}
bool ok() {
	rep(i,1,4) if (p[i]) {
		if (s[M(i+2)]) return 1;
		if (s[i]||l[i]||r[i]) return 1; //!
		if (r[M(i-1)]) return 1;
		if (l[M(i+1)]) return 1;
	}
	return 0;
}
int main()
{
	rep(i,1,4) {
		read(l[i]);read(s[i]);read(r[i]);read(p[i]);
	}
	if (ok()) puts("YES"); else puts("NO");
	return 0;
}