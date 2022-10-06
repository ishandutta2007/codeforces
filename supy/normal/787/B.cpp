#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,m;
int vis1[10005],vis[10005];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool Yes() {
	int x;
	memset(vis,-1,sizeof(vis)); //!!!
	memset(vis1,-1,sizeof(vis1));
	while (m--) {
		read(x);
		bool flag=0;
		rep(i,1,x) {
			int y; read(y);
			if (y>0) vis[y]=m;
			else vis1[-y]=m;
			if (y<0) y=-y;
			if (vis[y]==m&&vis1[y]==m) flag=1;
		}
		if (!flag) return 1;
	}
	return 0;
}
int main() {
	read(n); read(m);
	if (Yes()) printf("YES"); else puts("NO");
	return 0;
}