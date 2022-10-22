#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int m, n;
string s, ans;
set<int> ss;
set<int> ins;
set<int> pos[30];
bool ex[100010];

int main() {
	cin >> m >> s;
	n = s.size();
	for (int i = 0; i <= n - m; ++i) {
		ex[i] = 1;
	}

	rep(i, n) {
		int c = s[i] - 'a';
		pos[c].insert(i);
	}

	rep(c, 26) {
		rep(i, n) if (ex[i]) {
			auto p = ins.lower_bound(i + m);
			if (p != ins.begin()) {
				--p;
				if (*p >= i) {
					ex[i] = 0;
					continue;
				}
			}

			auto u = pos[c].lower_bound(i + m);
			if (u == pos[c].begin()) {
				continue;
			}

			--u;
			if (*u >= i) {
				ans.pb('a' + c);
				ins.insert(*u);
				ex[i] = 0;
				pos[c].erase(u);
			}
		}

		bool ok = 1;
		rep(i, n) if (ex[i]) {
			auto p = ins.lower_bound(i + m);

			bool sf = 0;
			if (p != ins.begin()) {
				--p;
				if (*p >= i) {
					sf = 1;
				}
			}
			
			if (!sf) ok = 0;
		}

		if (ok) break;

		for (int p : pos[c]) {
			ans.pb('a' + c);
			ins.insert(p);
		}
	}

	cout << ans << endl;
	return 0;
}