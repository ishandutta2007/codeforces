#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct Point { int x, y;
	int dot(Point p) {
		return x * p.x + y * p.y;
	}
};

int main() {
	ios :: sync_with_stdio(false);
	int a, b; cin >> a >> b;
	vector <Point> u, v;
	for(int i = 1; i < a; i ++)
		for(int j = 1; j < a; j ++)
			if(i * i + j * j == a * a) u.pb({i, j});
	for(int i = 1; i < b; i ++)
		for(int j = 1; j < b; j ++)
			if(i * i + j * j == b * b) v.pb({-j, i});

	for(auto p : u)
		for(auto q : v)
			if(p.y != q.y && p.dot(q) == 0) {
				cout << "YES\n0 0\n";
				cout << p.x << ' ' << p.y << '\n';
				cout << q.x << ' ' << q.y << '\n';
				return 0;
			}
	cout << "NO\n";
	return 0;
}