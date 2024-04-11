//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 105;

int read() { int x; cin >> x; return x; }

int a[N], ans[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	bool fl = 0;
	for (int i = 0; i < n; ++i) {
		memset(a, 0, sizeof a);
		for (int j = 0; j < n; ++j) {
			int x = read();
			a[x]++;
		}
		for (int j = 0; j <= n; ++j) if (!a[j]) {
			ans[i] = j - 1;
			if (j == n && !fl) {
				ans[i] = n;
				fl = 1;
			} else if (j == n) {
				ans[i] = n - 1;
			}
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
}