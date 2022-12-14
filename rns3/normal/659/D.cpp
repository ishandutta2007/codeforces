#include <bits/stdc++.h>
using namespace std;

#define N 10001
#define ep 1e-5

struct pnt {
	long long x, y;
	pnt (long long x = 0, long long y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const long long &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const long long &a) const { return pnt(x / a, y / a); }
	inline long long operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline long long operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%I64d %I64d", &x, &y); }
	void FastInput() {
		int a, b;
		scanf("%d %d", &a, &b);
		x = 1.0 * a;
		y = 1.0 * b;
	}
	inline void print() { printf("%I64d %I64d\n", x, y); }
	inline bool operator < (const pnt &a) const {
		if (fabs(x - a.x) > ep) return x < a.x;
		return y < a.y;
	}
	inline bool operator == (const pnt &a) const {
		return fabs(x - a.x) < ep && fabs(y - a.y) < ep;
	}
	inline pnt Rotate(const long long &angle) {
		pnt R = pnt(sin(angle), cos(angle)), C = *this;
		return pnt(C ^ R, C & R);
	}
	inline long long dist() { return sqrt(x * x + y * y); }
	inline pnt norm() { return (*this) / dist(); }
} p[N];

int calc(pnt A, pnt B, pnt C) {
    if(A.x == B.x) {
        if(B.y > A.y && C.x < B.x) return 1;
        if(B.y < A.y && C.x > B.x) return 1;
        return 0;
    }
    if(A.y == B.y) {
    	if(B.x > A.x && C.y > B.y) return 1;
		if(B.x < A.x && C.y < B.y) return 1;
		return 0;
    }
    while(1);
}

int main() {
	///freopen("D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) p[i].input();
	long long  area = 0;
	for(int i = 0; i < n; i ++) area += p[i] ^ (p[(i+1) % n]);
	if(area > 0) {
        reverse(p, p + n);
	}
	///for(int i = 0; i < n; i ++) p[i].print();
	int ans = 0;
	for(int i = 0; i < n; i ++) {
        ans += calc(p[i], p[(i+1)%n], p[(i+2)%n]);
	}
	cout << ans << endl;
}