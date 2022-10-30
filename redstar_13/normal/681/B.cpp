//2016-06-14 12:09:28.024000
#include <bits/stdc++.h>

using namespace std;

#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
typedef long long INT;
INT va=1234567, vb=123456, vc=1234;

int GCD(INT a, INT b, INT n, INT &x, INT &y) {
	if (b==0) {
		x=n/a; y=0;
	} else {
		INT xx, yy;
		GCD(b, a%b, n, xx, yy);
		y=(n-a*yy)/b;
		y%=a;
		if (y<0) y+=a;
		x=(n-b*y)/a; 
	}
}

int can(INT n) {
	if (n%__gcd(vb, vc)) return 0;
	INT x, y, d;
	d=__gcd(vb, vc);
		
	GCD(vb/d, vc/d, n/d, x, y);
	
	if (x>=0) return 1;
	return 0;
}

int main() {
	
	INT n, a;
	int yes=0;
	scanf("%I64d", &n);
	for (a=0; a*va<=n; a++) {
		if (can(n-a*va)) {
			yes=1; break;
		}
	}
	
	if (yes) puts("YES");
	else puts("NO");
	
	return 0; 
}