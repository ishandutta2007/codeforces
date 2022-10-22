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
	int id;
};

bool operator<(Point a, Point b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.z < b.z;
}

int dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

const int INF = 1e9 + 7;

set <int> xs;
map <int, set <int> > ys;
map <pair <int, int>, set <pair <int, int> > > zs;

void erase(Point a) {
	zs[{a.x, a.y}].erase({a.z, a.id});
	if (zs[{a.x, a.y}].empty()) {
		zs.erase({a.x, a.y});
		ys[a.x].erase(a.y);
		if (ys[a.x].empty()) {
			xs.erase(a.x);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	set <Point> q; 
	vector <Point> aa(n);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		aa[i] = {x, y, z, i};
		xs.insert(x);
		ys[x].insert(y);
		zs[{x, y}].insert({z, i});
		q.insert(aa[i]);
	}
	while (!q.empty()) {
		Point a = *q.begin();
		q.erase(q.begin());
		erase(a);
		auto it1 = xs.lower_bound(a.x);
		if (it1 == xs.end()) {
			it1--;
		}
		int x = *it1;
		auto it2 = ys[x].lower_bound(a.y);
		if (it2 == ys[x].end()) {
			it2--;
		}
		int y = *it2;
		auto it3 = zs[{x, y}].lower_bound({a.z, -INF});
		if (it3 == zs[{x, y}].end()) {
			it3--;
		}
		auto b = *it3;
		cout << a.id + 1 << " " << b.second + 1 << "\n";
		erase(aa[b.second]);
		q.erase(aa[b.second]);
	}
}