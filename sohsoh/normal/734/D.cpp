#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

vector<pair<int, char>> vec[4]; // row, col, diag 1, diag 2
int n, x0, wat_y;

inline bool f(vector<pair<int, char>> vec, int x, char c) {
	vec.push_back({x, 'K'});
	sort(all(vec));
	int ind = find(all(vec), make_pair(x, 'K')) - vec.begin();
	if (ind > 0 && vec[ind - 1].Y != c) return true;
	if (ind < int(vec.size()) - 1 && vec[ind + 1].Y != c) return true;
	return false;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> x0 >> wat_y;
	for (int i = 0; i < n; i++) {
		char c;
		int x, y;
		cin >> c >> x >> y;

		if (x == x0) vec[0].push_back({y, c});
		if (y == wat_y) vec[1].push_back({x, c});
		if ((x - x0) == (y - wat_y)) vec[2].push_back({x, c});
		if ((x - x0) == (wat_y - y)) vec[3].push_back({x, c});
	}

	cout << (f(vec[0], wat_y, 'B') || f(vec[1], x0, 'B') || f(vec[2], x0, 'R') || f(vec[3], x0, 'R') ? "YES" : "NO") << endl;
	return 0;
}