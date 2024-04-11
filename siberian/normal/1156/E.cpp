#include <bits/stdc++.h>

	using namespace std;
	//#define int long long

	vector <int> a;
	int n;

	inline void read() {
		cin >> n;
		a.resize(n);
		for (auto &i : a)
			cin >> i;
	}

	inline int f(int l, int r) {
		if (r - l <= 1)
			return 0;
		int m = (l + r) / 2;
		int ans = f(l, m) + f(m, r);

		map <int, int> have_left, have_right;
		int max_num = 0;
		for (int i = m - 1; i >= l; i--) {
			max_num = max(max_num, a[i]);
			have_left[a[i]] = max_num;
		}

		max_num = 0;
		for (int i = m; i < r; i++) {
			max_num = max(max_num, a[i]);
			have_right[a[i]] = max_num;
		}

		for (auto i : have_left) {
			int num = i.first;
			int max_num = i.second;
			if (have_right.count(max_num - num) == 0)
				continue;
			if (have_right[max_num - num] > max_num)
				continue;
			ans++;
		}

		for (auto i : have_right) {
			int num = i.first;
			int max_num = i.second;
			if (have_left.count(max_num - num) == 0)
				continue;
			if (have_left[max_num - num] > max_num)
				continue;
			ans++;
		}
		return ans;
	}

	int ans;
	inline void run() {
		ans = f(0, n);
	}

	inline void write() {
		cout << ans << endl;
	}

	signed main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		read();
		run();
		write();
		return 0;
	}