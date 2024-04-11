#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int count2(int x) {
	int cnt = 0;
	while ((x & 1) == 0) x >>= 1, cnt++;
	return cnt;
}

const int N = 2e5 + 10;

struct D {
	D(){}
	D(int x, int y):v(x), i(y){}
	int v, i;
	bool operator < (const D& t) const {
		return v > t.v;
	}
}f[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	int _, n;
	cin >> _;
	while (_--) {
		// cerr << "\n";
		cin >> n;
		for (int i = 1; i <= n; i++) {
			f[i] = D(count2(i), i);
		}
		sort(f + 1, f + n + 1);
		int cnt = 0;
		for (int a, i = 1; i <= n; i++) {
			cin >> a;
			cnt += count2(a);
		}
		if (cnt >= n) {
			cout << "0\n";
			continue;
		} else {
			std::vector<int> ans;
			for (int i = 1; cnt < n && i <= n; i ++) {
				cnt += f[i].v;
				ans.push_back(f[i].i);
			}
			if (cnt >= n) {
				cout << ans.size() << "\n";
				// for (int i : ans) cout << i << "\n";	
			} else {
				cout << "-1\n";
			}
		}
		
	}
	return 0;	
}