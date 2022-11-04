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

const int MAXBITS = 64;

vector<int> get_sums(const vector<int> &v, int n) {
	vector<int> a(v);
	for (auto &x : v) {
		a.pb(x);
	}
	vector<int> ans;
	for (int i = 0; i < 2 * n; ++i) {
		ans.pb(0);
		for (int j = 0; j < n; ++j) {
			ans.back() += a[i + j];
		}
	}
	return ans;
}

void run() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO" << endl;
		return;
	}
	vector<int> a(2 * n);
	int cur = 0;
	for (int i = 0; i < 2 * n; ++i) {
		a[cur] = i;
		if (i & 1) {
			++cur;
		} else {
			cur += n;
		}
		cur %= 2 * n;
	}
	cout << "YES" << endl;
	for (auto &x : a) {
		cout << x + 1 << " ";
	}
	cout << endl;
}