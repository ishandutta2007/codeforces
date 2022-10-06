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

const int N = 105;
int n,l,a[N],b[N];
int x[N],y[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge() {
	rep(i,1,n-1) x[i]=a[i+1]-a[i];
	x[n]=a[1]-a[n]+l;
	rep(i,1,n-1) y[i]=b[i+1]-b[i];
	y[n]=b[1]-b[n]+l;
	rep(i,0,n-1) {
		bool flag=1; 
		rep(j,1,n) {if (x[(i+j-1)%n+1]!=y[j]) flag=0;}
		if (flag) return 1;
	}
	return 0;
}
int main() {
	read(n); read(l);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	printf("%s",judge()?"YES":"NO");
	return 0;
}