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
#define abs(a) ((a)>0 ? (a) : (-a))
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;



inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll E(int x, int y, int p, int q) {
	int a=(x-1)/p+1,b=(y-x-1)/(q-p)+1;
	a=max(a,b); return (ll)a*q-y;
}
int main() {
//	freopen("1.in","r",stdin);
	int t; read(t);
	while (t--) {
		int x,y,p,q;
		read(x); read(y);
		read(p); read(q);
		if (p==q&&x<y || p==0&&x>0) {printf("-1\n"); continue;} //!!!
		if ((ll)x*q==(ll)y*p) {printf("0\n"); continue;}
		printf("%lld\n",E(x,y,p,q));
	}
	return 0;
}