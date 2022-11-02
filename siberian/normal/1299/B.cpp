#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct point{
	int x, y;
	point() {}
	point(int a, int b) {
		x = a, y = b;
	}
};

point operator-(const point & a, const point & b) {
	return point(a.x - b.x, a.y - b.y);
}

bool operator==(const point & a, const point & b) {
	return tie(a.x, a.y) == tie(b.x, b.y);
}

int n;
vector<point> a;

void no() {
	cout << "NO";
	exit(0);
}

void read() {
	cin >> n;
	if (n % 2) {
		no();
	}
	a.resize(n);
	for (auto &i : a)
		cin >> i.x >> i.y;
}

#define vec point

void run() {
	a.push_back(a[0]);
	for (int i = 0; i < n / 2; i++) {
		vec v1 = a[i + 1] - a[i];
		vec v2 = a[i + n / 2] - a[i + n / 2 + 1];
		if (v1 == v2) continue;
		no(); 
	}
}

void write() {
	cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}