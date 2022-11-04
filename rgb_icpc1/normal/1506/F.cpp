#include <bits/stdc++.h>

using namespace std;

void err_out() { cerr << endl; }
template<typename hd, typename... tl> void err_out(hd a, tl... b) { cerr << ' ' << a; err_out(b...); }
#ifdef LOCAL
#define err(...) cerr << "[" << #__VA_ARGS__ << "]:", err_out(__VA_ARGS__)
#else
#define err(...) 42
#endif

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

#define endl '\n'
#define MN 200005
using llint = long long;

typedef pair<int, int> pii;
pii p[MN];
int r[MN], c[MN];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> r[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		n++;
		p[0]= {0, 1};
		for (int i = 1; i < n; i++) {
			p[i] = {r[i] - c[i], c[i]};
		}
		sort(p, p + n);
		for (int i = 1; i < n; i++) {
			if (p[i - 1].first <= p[i].first && p[i - 1].second <= p[i].second) ;
			else while (1);
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
//			cout << p[i].first << ' ' << p[i].second << endl;
			if (p[i].first == p[i - 1].first) {
				if (p[i].first & 1) ;
				else ans += p[i].second - p[i - 1].second;
			}
			else {
				if ((p[i].first - p[i - 1].first) & 1) {
					ans += (p[i].first - p[i - 1].first) / 2;
					if (p[i - 1].first & 1) ans++;
				}
				else ans += (p[i].first - p[i - 1].first) / 2;
			}
//			cout << ans << endl;
		}
		cout << ans << endl;
	}

	return 0;
}