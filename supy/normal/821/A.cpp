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

int n,a[55][55];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge() {
	rep(i,1,n) rep(j,1,n) if (a[i][j]!=1) {
		bool flag=0;
		rep(k,1,n) rep(l,1,n)
			if (k!=i&&l!=j) {
				if (a[i][j]==a[i][l]+a[k][j]) flag=1;
			}
		if (!flag) return 0;
	}
	return 1;
}
int main() {
	read(n);
	rep(i,1,n)rep(j,1,n)read(a[i][j]);
	printf("%s",judge()?"Yes":"No");
	return 0;
}