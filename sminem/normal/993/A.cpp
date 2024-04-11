#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
};

int det(pt a, pt b, pt c) {
	return a.x*b.y+b.x*c.y+c.x*a.y
		-a.y*b.x-b.y*c.x-c.y*a.x;
}

pt a[5], b[5];

bool inside(pt p, pt* a) {
	int l = 0, g = 0;
	for (int i=0; i<4; i++) {
		int d = det(p, a[i], a[i+1]);
		if (d < 0)
			l++;
		else if (d > 0)
			g++;
	}
	return l == 0 || g == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<4; i++)
		cin >> a[i].x >> a[i].y;
	a[4] = a[0];

	for (int i=0; i<4; i++)
		cin >> b[i].x >> b[i].y;
	b[4] = b[0];

	for (int i=0; i<=4; i++) {
		a[i].x *= 2;
		a[i].y *= 2;
		b[i].x *= 2;
		b[i].y *= 2;
	}

	for (int i=-500; i<=500; i++)
		for (int j=-500; j<=500; j++)
			if (inside({i, j}, a) && inside({i, j}, b))
				return cout << "YES\n", 0;

	cout << "NO\n";
}