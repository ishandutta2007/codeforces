#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,a[100005],ans;
inline int gcd(int x, int y) {
	return y==0 ? x : gcd(y,x%y);
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int trans(int p) {
	if (a[p]==1&&a[p+1]==1) {a[p]=a[p+1]=0;}
	else {a[p]=a[p+1]=1;}
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	int GCD=a[1]; puts("YES");
	rep(i,2,n) GCD=gcd(GCD,a[i]);
	if (GCD>1) {puts("0"); return 0;}
	rep(i,1,n) a[i]&=1;
	rep(i,1,n) if (a[i]==1) {
		while (a[i]==1)	{trans(i); ans++;}
	}
	printf("%d",ans);
	return 0;
}