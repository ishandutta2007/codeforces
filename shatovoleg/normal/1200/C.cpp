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

void run() {
	int n, m, q;
	cin >> n >> m >> q;
	int g = __gcd(n, m);
	n /= g;
	m /= g;
	for (int i = 0; i < q; ++i) {
		int c1, s1, c2, s2;
		cin >> c1 >> s1 >> c2 >> s2;
		--s1, --s2;
		if (c1 == 1) {
			s1 /= n;
		} else {
			s1 /= m;
		}
		if (c2 == 1) {
			s2 /= n;
		} else {
			s2 /= m;
		}
		if (s1 == s2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}