#include <bits/stdc++.h>
#define ll long long
#define double long double

using namespace std;

const double PI = acos(-1);

struct Vector {
	int x, y, id;
};

int operator%(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

int operator*(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

double angle(Vector a, Vector b) {
	return atan2(a * b, a % b);	
}

Vector t = {1, 0, -1};
const double EPS = 1e-30;

bool operator<(Vector a, Vector b) {
	if (a * t == 0 && b * t == 0) {
		return a.x > 0;
	}
	if ((a * t < 0) != (b * t < 0)) {
		return a * t < 0;
	}
	return a * b > 0;
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;	
	vector <Vector> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
		//cout << angle(a[i], t) << "\n";
	} 
	sort(a.begin(), a.end());
	double now = 1e9 + 7;
	int p = -1, r = -1;
	for (int i = 0; i < n; i++) {
		Vector x = a[i], y = a[(i + 1) % n];
		double ang = angle(x, y);
		//cout << ang << "\n";
		if (ang < -EPS) {
			ang += 2 * PI;
		}
		ang = min(ang, 2 * PI - ang);
		//cout << x.id << "\n";
		//cout << x.id << " " << y.id << " " << ang << "\n";
		if (now > ang) {
			now = ang;
			p = x.id, r = y.id;
		}
	}
	cout << p + 1 << " " << r + 1 << "\n";
}