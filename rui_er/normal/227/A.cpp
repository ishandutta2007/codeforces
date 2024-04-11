//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Vector {
	double x, y;
	Vector() : x(0), y(0) {}
	Vector(double a, double b) : x(a), y(b) {}
	Vector friend operator + (const Vector &a, const Vector &b) {
		return Vector(a.x+b.x, a.y+b.y);
	}
	Vector friend operator - (const Vector &a, const Vector &b) {
		return Vector(a.x-b.x, a.y-b.y);
	}
	double friend operator * (const Vector &a, const Vector &b) {
		return a.x * b.x + a.y * b.y;
	}
	double friend operator ^ (const Vector &a, const Vector &b) {
		return a.x * b.y - a.y * b.x;
	}
}a[3];

int main() {
	rep(i, 0, 2) scanf("%lf%lf", &a[i].x, &a[i].y);
	double qwq = (a[1] - a[0]) ^ (a[2] - a[1]);
	puts(qwq==0.0?"TOWARDS":qwq>0.0?"LEFT":"RIGHT");
	return 0;
}