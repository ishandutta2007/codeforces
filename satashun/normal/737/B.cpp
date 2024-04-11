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

int n, a, b, k;
string s;
vi ans;
set<pii> st;

int main() {
	cin >> n >> a >> b >> k;
	cin >> s;
	int la = -1;

	rep(i, n) {
		if (s[i] == '1') {
			if (la != -1) {
				st.insert(mp(la, i-1));
				la = -1;
			}
		} else {
			if (la == -1) {
				la = i;
			}
		}
	}

	if (la != -1) {
		st.insert(mp(la, n-1));
	}

	int u = 0;
	for (pii p : st) {
		u += (p.se - p.fi + 1) / b;
	}

	while (u >= a) {
		auto it = st.begin();
		pii p = *it;
		bool ok = 0;

		if (p.se - p.fi + 1 >= b) {
			ok = 1;
			ans.pb(p.fi + b - 1);
			p.fi += b;
			--u;
		}

		st.erase(it++);
		if (ok) st.insert(p);
	}

	cout << ans.size() << endl;
	rep(i, (int)ans.size()) printf("%d%c", ans[i] + 1, i == (int)ans.size()-1 ? '\n' : ' ');

	return 0;
}