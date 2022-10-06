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
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 500005
int n;
int col[N];
struct Rec {
	int x0,y0,x1,y1,index;
} r[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);
	rep(i,1,n){read(r[i].x0);read(r[i].y0);read(r[i].x1);read(r[i].y1);r[i].index=i;}
	rep(i,1,n) col[i]=(r[i].x0&1)*2+(r[i].y0&1)+1;
	puts("YES");
	rep(i,1,n) printf("%d\n",col[i]);
	return 0;
}