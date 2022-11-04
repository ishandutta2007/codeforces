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
	string s, t;
	cin >> s >> t;
	int n = len(s), m = len(t);
	vector<int> pref(n + 1, 0), suff(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i];
		if (pref[i] < m && s[i] == t[pref[i]]) {
			++pref[i + 1];
		}
	}
	reverse(all(t));
	for (int i = n - 1; i > -1; --i) {
		suff[i] = suff[i + 1];
		if (suff[i] < m && s[i] == t[suff[i]]) {
			++suff[i];
		}
	}
	int l = -1, r = n + 1;
	while (r - l > 1) {
		int c = (r + l) >> 1;
		bool good = false;
		for (int i = 0; i + c <= n; ++i) {
			if (pref[i] + suff[i + c] >= m) {
				good = true;
			}
		}
		if (good) {
			l = c;
		} else {
			r = c;
		}
	}
	cout << l << endl;
}