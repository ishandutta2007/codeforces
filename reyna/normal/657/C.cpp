//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
#define try trieO_O
const int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

int bg[N], ed[N], a[5][N], p[N];


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), k = read(), b = read(), c = read();
	smin(b, c * 5);
	rep(i, n) {
		cin >> p[i];
		p[i] += 1e9;
	}
	int res = 3e18;
	sort(p, p + n);
	rep(i, n)
		a[p[i] % 5][ed[p[i] % 5]++] = i;
	rep(g, 5) {
		memset(bg, 0, sizeof bg);
		vector<int> try;
		rep(j, 3)
			rep(i, n)
				try.push_back((p[i] / 5 + j - 1) * 5 + g);
		sort(try.begin(), try.end());
		int cur = 0, j = 0, added = 0;
		rep(i, 3 * n) {
			int x = try[i];
			while (j < n && p[j] <= x) {
				cur += (x - p[j]) / 5 * b + ((x - p[j]) % 5) * c;
				j++;
				added++;
			}
			while (added > k) {
				int mx = -3e18, group = -1;
				rep(rem, 5) {
					if (bg[rem] < ed[rem] && p[a[rem][bg[rem]]] <= x && mx < (x - p[a[rem][bg[rem]]]) / 5 * b + ((x - p[a[rem][bg[rem]]]) % 5) * c) {
						mx = (x - p[a[rem][bg[rem]]]) / 5 * b + ((x - p[a[rem][bg[rem]]]) % 5) * c;
						group = rem;
					}
				}
				assert(group != -1);
				bg[group]++;
				cur -= mx;
				added--;
			}
			if (added == k)
				smin(res, cur);
			if (i != 3 * n - 1)
				cur += (try[i + 1] - try[i]) / 5 * b * added;
		}
	}
	cout << res << endl;
}