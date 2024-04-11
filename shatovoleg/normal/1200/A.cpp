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
	int n;
	cin >> n;
	vector<int> is_taken(10, 0);
	string s;
	cin >> s;
	for (auto &x : s) {
		if (x == 'L') {
			for (int i = 0; i < 10; ++i) {
				if (!is_taken[i]) {
					is_taken[i] = 1;
					break;
				}
			}
		} else if (x == 'R') {
			for (int i = 9; i > -1; --i) {
				if (!is_taken[i]) {
					is_taken[i] = 1;
					break;
				}
			}
		} else {
			is_taken[x - '0'] = 0;
		}
	}
	for (auto &x : is_taken) {
		cout << x;
	}
	cout << endl;
}