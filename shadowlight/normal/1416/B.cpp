#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Op {
	int i, j, x;
};

vector <Op> ops;
vector <int> a;

void do_op(int i, int j, int x) {
	if (!x) return;
	a[i] -= x * (i + 1);
	a[j] += x * (i + 1);
	//assert(a[i] >= 0);
	//assert(a[j] >= 0);
	ops.pb({i, j, x});
}


void solve() {
	int n;
	cin >> n;
	ops.clear();
	a.assign(n, 0);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n) {
		cout << "-1\n";
		return;
	}

	vector <pair <int, int>> need;
	vector <pair <int, int>> over;

	for (int i = 1; i < n; ++i) {
		int T = (i + 1);
		need.pb({(T - a[i] % T) % T, i});
		over.pb({a[i] / T * T, i});
	}
	sort(need.begin(), need.end());
	sort(over.begin(), over.end());
	for (auto t : need) {
		int i = 0, j = t.y;
		while (over.size() && a[0] < t.x) {
			int x = over.back().x, k = over.back().y;
			over.pop_back();
			if (!a[k]) continue;
			do_op(k, i, x / (k + 1));
		}
		//cout << a[0] << " " << t.x << endl;
		if (a[0] >= t.x) {
			do_op(i, j, t.x);
			do_op(j, i, a[j] / (j + 1));
			continue;
		} else {
			cout << "-1\n";
			return;
		}
	}
	int val = sum / n;
	for (int i = 1; i < n; ++i) {
		do_op(0, i, val);
	}

	assert(ops.size() <= 3 * n);
	cout << ops.size() << "\n";
	for (auto t : ops) {
		cout << t.i + 1 << " " << t.j + 1 << " " << t.x << "\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}