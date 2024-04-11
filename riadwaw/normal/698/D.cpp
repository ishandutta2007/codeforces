#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using vi = vector<int>;
void solve();


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	auto start = clock();
#endif
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	cerr << endl << endl << (clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
	return 0;
}

//#define int li

auto& in = std::cin;
auto& out = std::cout;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return abs(a);
}
struct Point {
	int x, y;
	int id;

	Point norm() {
		int g = gcd(x, y);
		return Point{ x / g, y / g, -1 };
	}
};

Point operator - (const Point& a, const Point& b) {
	return Point{ a.x - b.x, a.y - b.y, -1 };
}


bool operator < (const Point& a, const Point& b) {
	return tie(a.x, a.y) < tie(b.x, b.y);
}



void solve() {
	int k, n;
	in >> k >> n;
	vector<Point> spots(k);
	vector<Point> medveds(n);
	for (int i = 0; i < k; ++i) {
		in >> spots[i].x >> spots[i].y;
		spots[i].id = i;
	}

	for (int i = 0; i < n; ++i) {
		in >> medveds[i].x >> medveds[i].y;
		medveds[i].id = i;
	}

	vector<map<Point, map<int, int>>> dir2medveds(k);

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			Point dir = medveds[j] - spots[i];
			int g = gcd(dir.x, dir.y);
			Point norm = dir.norm();
			dir2medveds[i][norm][g] = j;
		}
	}

	vector<vector<vector<int>>> medved2medveds(k, vector<vector<int>>(n));
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			Point dir = medveds[j] - spots[i];
			dir = dir.norm();
			medved2medveds[i][j].reserve(k);
			for (auto& x : dir2medveds[i][dir]) {
				medved2medveds[i][j].push_back(x.second);
				if (medved2medveds[i][j].size() == k) {
					break;
				}
			}
		}
	}

	vector<int> order(k);
	vector<int> used(n);
	for (int i = 0; i < k; ++i) {
		order[i] = i;
	}
	int TIMER = 32;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		sort(all(order));
		auto solve = [&]() {
			vector<int> need = { i };
			int pos = 0;
			used[i] = TIMER;
			while (!need.empty()) {
				if (need.size() + pos > k) {
					return false;
				}
				sort(all(need));
				int now = need.back();
				need.pop_back();
				for (int x : medved2medveds[order[pos]][now]) {
					if (x == now) {
						break;
					}
					if (used[x] == TIMER) {
						continue;
					}
					
					used[x] = TIMER;
					need.push_back(x);
				}
				used[now] = TIMER;
				++pos;
			}
			return true;
		};
		do {
			++TIMER;
			if (solve()) {
				++ans;
				break;
			}
		}
		while (next_permutation(all(order)));
	}

	out << ans;
}