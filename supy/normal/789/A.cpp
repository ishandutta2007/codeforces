#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,k,a[100005],ans;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(k); rep(i,1,n) read(a[i]);
	rep(i,1,n) ans+=(a[i]-1)/k+1;
	printf("%d\n",(ans+1)/2);
	return 0;
}