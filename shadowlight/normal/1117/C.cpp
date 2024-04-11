#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll D = 4;
vector <ll> dx = {0, 0, -1, 1};
vector <ll> dy = {-1, 1, 0, 0}; 
const ll INF = 1e18 + 7;

string t = "DULR";

vector <int> ind(3000);

ll x, y, x2, y2;
ll n;
ll sx = 0, sy = 0;
string s;

bool can(ll len) {
	ll d = (len / n);
	ll nx = x + d * sx, ny = y + d * sy;
	for (ll i = 0; i < len % n; i++) {
		nx += dx[ind[s[i]]];
		ny += dy[ind[s[i]]];
	}
	//cout << nx << " " << ny << "\n";
	ll sum = abs(nx - x2) + abs(ny - y2);
	//cout << sum << " " << len << "\n";
	if (sum <= len) {
		return true;
	}  else {
		return false;
	}
}

void solve() {
	cin >> x >> y >> x2 >> y2;
	cin >> n;
	for (int i = 0; i < D; i++) {
		ind[t[i]] = i;
	}
	sx = 0, sy = 0;
	cin >> s;
	for (char c : s) {
		sx += dx[ind[c]];
		sy += dy[ind[c]];
		//cout << dx[ind[c]] << " " << dy[ind[c]] << "\n";
	}
	ll lt = 0, rt = INF;
	while (rt - lt > 1) {
		ll mt = (lt + rt) / 2;
		if (can(mt)) {
			rt = mt;
		} else {
			lt = mt;
		}
	}
	cout << (rt == INF ? -1 : rt) << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}