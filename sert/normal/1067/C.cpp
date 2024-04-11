#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int go(vector<pair<int, int>> v) {
	map<pair<int, int>, int> mp;
	set<pair<int, int>> s;
	queue<pair<int, int>> q;

	for (auto p: v) {
		s.insert(p);
		for (int i = 0; i < 8; i++) {
			pair<int, int> kk = make_pair(p.first + dy[i], p.second + dx[i]);
			mp[kk]++;			
		}
	}

	for (auto it: mp) {
		if (s.find(it.first) == s.end() && it.second >= 4) {
			q.push(it.first);
		}
	}

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		s.insert(p);
		for (int i = 0; i < 8; i++) {
			pair<int, int> kk = make_pair(p.first + dy[i], p.second + dx[i]);
			mp[kk]++;
			if (mp[kk] == 4 && s.find(kk) == s.end()) {
				q.push(kk);
			}
		}
	}

	return s.size();
}

int goRect(int n) {
	n /= 2;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(i, 1));
		v.push_back(make_pair(i, 2));
	}
	return go(v);
}

int goStrips(int n) {
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(i / 2, 4 * (i % 2)));
	}
	if ((int)v.size() > n) exit(12);
	return go(v);
}

int goCross(int n) {
	vector<pair<int, int>> v = {{0, 0}};
	for (int i = 0; i < (n - 1) / 4; i++) {
		v.push_back(make_pair(0, i + 1));
		v.push_back(make_pair(0, -i - 1));
		v.push_back(make_pair(i + 1, 0));
		v.push_back(make_pair(-i - 1, 0));
	}

	int rem = (n - 1) % 4;
	for (int i = 0; i < rem; i++) {
		v.push_back(make_pair(v.back().first - 1, 0));
	}

	if ((int)v.size() > n) exit(11);

	return go(v);
}

double toKek(int res, int n) {
	return (res + 0.0) / (n * n);
}

void solve() {
	/*for (int i = 1; i <= 100; i++) {
		int ans = goStrips(i);
		printf("%3d %3d %.4f | ", i, ans, toKek(ans, i));
		ans = goCross(i);
		printf("%3d %3d %.4f\n", i, ans, toKek(ans, i));
	}*/	
	int n;
	cin >> n;
	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};
	if (n <= 20) {
		for (int i = 0; i < n; i++) {
			cout << i / 2 << " " << 4 * (i % 2) << "\n";
		}
	} else {
		cout << "0 0\n";
		for (int i = 1; i < n; i++) {
			int len = (i + 3) / 4;
			int dir = (i - 1) % 4;
			cout << len * dx[dir] << " " << len * dy[dir] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}