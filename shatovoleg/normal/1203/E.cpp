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
	vector<int> cnt(1000000, 0);
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	sort(all(v));
	for (auto &x : v) {
		if (x > 1) {
			if (!cnt[x - 1]) {
				cnt[x - 1] = 1;
				continue;
			}
		}
		if (!cnt[x]) {
			cnt[x] = 1;
			continue;
		}
		if (!cnt[x + 1]) {
			cnt[x + 1] = 1;
			continue;
		}
	}
	int ans = 0;
	for (auto &x : cnt) {
		if (x) {
			++ans;
		}
	}
	cout << ans << endl;
}