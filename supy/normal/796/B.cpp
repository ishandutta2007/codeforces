#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,m,k,x,y,ans;
bool Hole[1000005];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int solve() {
	if (Hole[1]) return 1;
	int ans=1;
	rep(i,1,k) {
		read(x); read(y);
		if (x==ans) ans=y;
		else if (y==ans) ans=x;
		if (Hole[ans]) return ans;
	}
	return ans;
}
int main() {
	read(n); read(m); read(k);
	rep(i,1,m) {int x; read(x); Hole[x]=1;}
	printf("%d",solve());
	return 0;
}