#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2500;
int n, p[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		bool d = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			d &= p[i] % 2 == i % 2;
		}
		if (!d) {
			cout << "-1\n";
			continue;
		}
		vector<int> op;
		auto go = [&](int x) {
			reverse(p + 1, p + x + 1);
			op.push_back(x);
		};
		for (int i = n; i > 1; i -= 2) {
			for (int j = 1; j <= i; j += 2) {
				if (p[j] == i) {
					go(j);
					break;
				}
			}
			for (int j = 1; j < i; j += 2) {
				if (p[j + 1] == i - 1) {
					go(j);
					go(j + 2);
					go(3);
					go(i);
					break;
				}
			}
		}
		cout << op.size() << '\n';
		for (int x : op) cout << x << ' ';
		cout << '\n';
		for (int i = 1; i <= n; ++i) assert(p[i] == i);
	}
}

//  n  1 n-1   n, n-1n-1 3 