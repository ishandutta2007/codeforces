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

const ll MOD = 1000000007;

const int N = 1000010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[N + 1];
	int n;

public:
	BIT() {
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		T s = 0;
		++i;
		while (i > 0) {
			s += bit[i];
			s %= MOD;
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			bit[i] %= MOD;
			i += i & -i;
		}
	}
};

BIT<ll> T;
int n, m, k;
vector<pii> in[1000010];
vector<pii> out[1000010];
set<int> alive;
set<pii> itv;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	alive.insert(1);
	itv.insert(mp(0,0));

	rep(i, k) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		in[b].pb(mp(a,c));
		out[d+1].pb(mp(a,c));
	}

	T.add(1, 1);

	for (int i = 1; i <= m; ++i) if (in[i].size() > 0 || out[i].size() > 0) {
		sort(ALL(in[i])); sort(ALL(out[i]));

		vector<pair<int,ll>> vals;

		rep(j, in[i].size()) {
			pii p = in[i][j];
			auto it = itv.upper_bound(mp(p.se+1,n));
			//cout<<p.fi<<" "<<p.se<<" "<<it->fi<<" "<<it->se<<endl;
			--it;

			if (it->se < p.se + 1) {

				ll num = T.sum(p.se) - T.sum(it->se);
			//cout<<num<<endl;
				num %= MOD;
				if (num < 0) num += MOD;

				vals.eb(p.se + 1, i>1?num:0LL);
				if (i>1) alive.insert(p.se + 1);
			}
		}

		for (pii p : out[i]) {
			itv.erase(p);
		}

		rep(j, vals.size()) {
			T.add(vals[j].fi, vals[j].se);
		}

		rep(j, in[i].size()) {
			pii p = in[i][j];
			itv.insert(p);

			auto it = alive.lower_bound(p.fi);
			while (it != alive.end() && *it <= p.se) {
				int pos = *it;
				ll k = T.sum(pos) - T.sum(pos-1);
				k %= MOD;
				T.add(pos, MOD-k);
				alive.erase(it++);
			}
		}
/*
		printf("DEBUG:i=%d\n", i);
		for (int j=1;j<=n;++j) {
			cout<<T.sum(j)-T.sum(j-1)<<" ";
		}
		cout<<endl;*/
	}

	ll ret = T.sum(n);
	auto it = itv.end();
	--it;
	ret = (ret - T.sum(it->se)) % MOD;
	if (ret < 0) ret += MOD;

	printf("%d\n", (int)ret);
	return 0;
}