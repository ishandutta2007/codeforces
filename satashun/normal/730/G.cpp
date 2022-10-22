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

int n;
pii u[210];

bool is(pii p, pii q)
{
	if (p.fi >= q.fi && p.fi <= q.se) return 1;
	if (p.se >= q.fi && p.se <= q.se) return 1;
	if (q.fi >= p.fi && q.fi <= p.se) return 1;
	if (q.se >= p.fi && q.se <= p.se) return 1;
	return 0;
}

int main() {
	cin >> n;

	rep(i, n) {
		int s, d;
		cin >> s >> d;
		bool t = 1;

		rep(j, i) {
			if (is(u[j], mp(s, s+d-1))) {
				t = 0;
			}
		}

		if (t) {
			u[i] = mp(s, s+d-1);
		} else {
			int l = 2e9;
			vector<pii> cand;
			cand.eb(1, d);
			rep(j, i) {
				cand.eb(u[j].se+1, u[j].se+d);
			}
			for (pii p : cand) {
				bool f = 1;
				rep(j, i) {
					if (is(u[j], p)) {
						f = 0;
					}
				}
				if (f) l = min(l, p.fi);
			}
			u[i] = mp(l, l+d-1);
		}

		printf("%d %d\n", u[i].fi, u[i].se);
	}

	return 0;
}