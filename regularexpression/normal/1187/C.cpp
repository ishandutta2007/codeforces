#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<random>
#include<functional>
#include<set>
#include<map>
#include<string>
#include<chrono>
#include<cassert>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, l, r) for (int i = (l); i < (r); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;

const int inf = (int)1e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n, inf);
	vector<bool> b(n, false);
	vector<pair<int, int>> qs;
	forn(q, m) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			fore(i, l, r) {
				b[i] = true;
			}
		} else {
			qs.emplace_back(l, r);
		}
	}
	forn(q, sz(qs)) {
		int cnt = 0;
		fore(i, qs[q].first, qs[q].second) {
			if (!b[i]) {
				++cnt;
			}
		}
		if (cnt == 0) {
			cout << "NO";
			return 0;
		}
	}
	int num = inf - 1;
	fore(i, 1, n) {
		if (!b[i]) {
			if (b[i - 1]) {
				a[i] = num;
			} else {
				a[i] = a[i - 1] - 1;
			}
		}
	}
	cout << "YES\n";
	forn(i, n) {
		cout << a[i] << " ";
	}
	return 0;
}