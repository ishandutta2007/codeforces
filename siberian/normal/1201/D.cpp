#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (y > x) x = y;}
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}

struct point{
	int x, y, dist;
	point() {
		x = 0, y = 0, dist = 1e17;
	}
	point(int a, int b) {
		x = a, y = b, dist = 1e17;
	}
};

bool operator<(point a, point b) {
	return tie(a.x, a.y) < tie(b.x, b.y);
}

int n, m, k, q;
vector<point> a;
vector<int> b;
void read() {
	cin >> n >> m >> k >> q;
	a.resize(k);
	for (auto &i : a)
		cin >> i.x >> i.y;
	b.resize(q);
	for (auto &i : b)
		cin >> i;
}

map <int, vector<point> > table;

void build() {
	sort(a.begin(), a.end());
	vector<point> help;
	help.push_back(a[0]);
	help.push_back(a[1]);

	for (int i = 2; i < k; i++) {
		while (help.size() >= 2) {
			int last = help.size() - 1;
			if (help[last].x == help[last - 1].x && help[last].x == a[i].x) {
				help.pop_back();
			}
			else {
				break;
			}
		}
		help.push_back(a[i]);
	}

	a = help;
	k = a.size();

	sort(b.begin(), b.end());

	for (auto i : a) {
		table[i.x].push_back(i);
	}
}

void relax(point s, point &f) {
	int pos1 = lower_bound(b.begin(), b.end(), s.y) - b.begin();
	if (pos1 >= 0 && pos1 < b.size()) {
		chkmin(f.dist, s.dist + (abs(s.y - b[pos1]) + abs(f.y - b[pos1])) * (s.x != f.x) + abs(s.y - f.y) * (s.x == f.x) + abs(s.x - f.x));
	}
	pos1--;
	if (pos1 >= 0 && pos1 < b.size()) {
		chkmin(f.dist, s.dist + (abs(s.y - b[pos1]) + abs(f.y - b[pos1])) * (s.x != f.x) + abs(s.y - f.y) * (s.x == f.x) + abs(s.x - f.x));
	}
}

void wr() {
	for (auto i : table) {
		cout << "level = " << i.first << endl;
		for (auto j : i.second) {
			cout << j.x << " " << j.y << " " << j.dist << endl;
		}
	}
}

int ans;

void run() {
	build();
	point s = point(1, 1);
	s.dist = 0;

	for (auto &i : table.begin()->second) {
		relax(s, i);
	}

	vector<int> have_x;
	set<int> help;
	for (auto i : table) {
		help.insert(i.first);
	}
	for (auto i : help)
		have_x.push_back(i);

	for (int i = 0; i < have_x.size() - 1; i++) {
		int d = 0;
		if (table[have_x[i]].size() == 2) {
			d = abs(table[have_x[i]][0].y - table[have_x[i]][1].y);
			int d1 = table[have_x[i]][0].dist;
			int d2 = table[have_x[i]][1].dist;
			table[have_x[i]][0].dist = d2 + d;
			table[have_x[i]][1].dist = d1 + d;
		}
		for (auto s : table[have_x[i]]) {
			for (auto &f : table[have_x[i + 1]]) {
				relax(s, f);
			}
		}
	}

	int f = have_x.back();
	int d = 0;
	if (table[f].size() == 2) {
		d = abs(table[f][0].y - table[f][1].y);
	}
	for (auto &s : table[f])
		s.dist += d;
	ans = 1e18;
	for (auto i : table[f])
		chkmin(ans, i.dist);
}

void write() {
	cout << ans << endl;
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