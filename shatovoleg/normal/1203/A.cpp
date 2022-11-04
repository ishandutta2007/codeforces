#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto &x : p) {
		cin >> x;
	}
	while (p[0] != 1) {
		p.pb(p[0]);
		p.erase(p.begin());
	}
	vector<int> P(n);
	iota(all(P), 1);
	if (p == P) {
		cout << "YES" << endl;
		return;
	}
	p.pb(p[0]);
	p.erase(p.begin());
	reverse(all(P));
	if (p == P) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

void run() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}