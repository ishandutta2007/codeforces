#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n;
struct ELE {int x,y,p;} a[100005];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int cmp(ELE a, ELE b) {
	return a.x>b.x;
}
int main() {
	read(n);
	rep(i,1,n) a[i].p=i;
	rep(i,1,n) read(a[i].x);
	rep(i,1,n) read(a[i].y); a[n+1].y=0;
	sort(a+1,a+n+1,cmp);
	printf("%d\n",n/2+1);
	/*if (n&1) {
		printf("%d",a[1].p);
		for (int i=2; i<=n; i+=2)
			if (a[i].y>=a[i+1].y) printf(" %d",a[i].p);
			else printf(" %d",a[i+1].p);
	}
	else {
		printf("%d %d",a[1].p,a[2].p);
		for (int i=3; i<=n; i+=2)
			if (a[i].y>=a[i+1].y) printf(" %d",a[i].p);
			else printf(" %d",a[i+1].p);
	}*/
	printf("%d",a[1].p);
	for (int i=2; i<=n; i+=2)
		if (a[i].y>=a[i+1].y) printf(" %d",a[i].p);
		else printf(" %d",a[i+1].p);
	return 0;
}