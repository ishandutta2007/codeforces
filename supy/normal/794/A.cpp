#include<cstdio>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;

int a,b,c,n,x[100006];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(b); read(a); read(c);
	read(n);
	rep(i,1,n) read(x[i]);
	sort(x+1,x+n+1);
	printf("%d",upper_bound(x+1,x+n+1,c-1)-lower_bound(x+1,x+n+1,a+1));
	return 0;
}