#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <bool> erased;

struct Point {
	int x, y, z;
};

int dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	erased.resize(n, false);
	for (int i = 0; i < n; i++) {
		if (erased[i]) continue;
		int now = INF, p = -1;
		for (int j = i + 1; j < n; j++) {
			if (erased[j]) continue;
			if (dist(a[i], a[j]) < now) {
				now = dist(a[i], a[j]);
				p = j;
			}
		}
		erased[i] = true, erased[p] = true;
		cout << i + 1 << " " << p + 1 << "\n";
	}
}