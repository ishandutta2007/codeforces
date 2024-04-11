#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,m,k;
int a[150],ans=1000000;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(m); read(k);
	rep(i,1,n) read(a[i]);
	rep(i,m+1,n) if (a[i]>0&&a[i]<=k) {ans=i-m; break;}
	for (int i=m-1; i>=1; i--)
		if (a[i]>0&&a[i]<=k) {ans=min(ans,m-i); break;}
	printf("%d",ans*10);
	return 0;
}