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
const int N = 100005;
int n,l,r;
struct E {int a,p,index;} q[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int s[N],b[N],ans[N];
bool cmp(E x, E y) {
	return x.p<y.p;
}
bool ok() {
	sort(q+1,q+n+1,cmp);
	b[q[1].index]=l-q[1].a; ans[q[1].index]=l;
	rep(i,2,n) {
		int x=b[q[i-1].index]+1;
		if (x<l-q[i].a) x=l-q[i].a;
		if (x>r-q[i].a) return 0;
		b[q[i].index]=x;
		ans[q[i].index]=x+q[i].a;
	}
	return 1;
}
int main() {
	read(n);read(l);read(r);
	rep(i,1,n) read(q[i].a);
	rep(i,1,n) read(q[i].p);
	rep(i,1,n) q[i].index=i;
	if (ok()) {
		rep(i,1,n) printf("%d ",ans[i]);
	} else puts("-1");
	return 0;
}