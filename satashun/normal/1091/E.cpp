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
#define dump(x) cout << #x << " = " << (x) << endl

const int SZ = (1 << 19);

struct starry_sky_tree {
    ll all[SZ * 2], mi[SZ * 2];

    void init() {
        memset(all, 0, sizeof(all));
        memset(mi, 0, sizeof(mi));
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        mi[k] = min(mi[k * 2 + 1] + all[k * 2 + 1], mi[k * 2 + 2] + all[k * 2 + 2]);
    }

    ll ask(int a, int b, int k = 0, int l = 0, int r = SZ) {
    	if (r <= a || b <= l) return LLONG_MAX;
    	if (a <= l && r <= b) return mi[k] + all[k];
    	ll lc = ask(a, b, k * 2 + 1, l, (l + r) / 2);
    	ll rc = ask(a, b, k * 2 + 2, (l + r) / 2, r);
    	return min(lc, rc) + all[k];
    }
} seg;

const int MN = 500010;

int n;
int a[MN];
ll aff[MN];

void dec(int i, int x) {
	seg.add(i, n, 1ll);

	if (x == 0) return ;
	int p = x - 1;
	if (p < i) {
		seg.add(p, i, -1);
	}
}

int main() {
	scanf("%d", &n);
	int n0 = 0;
	ll s = 0;

	rep(i, n) {
		scanf("%d", &a[i]);
		if (a[i] > 0) {
			++n0;
		}
		s += a[i];
	}

	s %= 2;

	sort(a, a + n);
	reverse(a, a + n);

	int ap = n;
	ll suf = 0;
	ll ac = 0;

	seg.init();

	rep(i, n) {
		ll k = i + 1;
		ac += a[i];

		while (ap > 0 && a[ap] <= k) {
			suf += a[ap];
			--ap;
		}
		ll rt = max<ll>(0LL, ap - i);
		ll bb = rt * k + suf + k * (k - 1) - ac;
		aff[i] = bb;
		seg.add(i, i + 1, bb);
	}

	vector<pii> vec(n);
	rep(i, n) {
		vec[i] = mp(a[i], i);
	}

	sort(ALL(vec));
	reverse(ALL(vec));

	vi cand;

	for (int i = 0; i <= n; ++i) {
		bool ok = ((s + i) % 2 == 0ll) && (i <= n0);
		ll c = seg.ask(0, n);
		if (c < 0) {
			ok = false;
		}

		if (ok) {
			cand.pb(i);
		}

		if (i < n) {
			auto e = vec[i];
			int pos = e.se, val = e.fi;
			dec(pos, val);
		}
	}

	int num = cand.size();
	if (num == 0) {
		puts("-1");
	} else {
		rep(i, num) {
			printf("%d%c", cand[i], (i == num - 1 ? '\n' : ' '));
		}
	}

	return 0;
}