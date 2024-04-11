#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define sz(a) ((int)(a.size()))
#define fs first
#define sc second

typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t uint;

typedef ve< int > vi;
typedef pa< int, int > pii;
typedef ve< pii > vpii;
typedef tu< int, int, int > tiii;

int n, q;
vi a, l, r;
int bl_len, bl_cnt;
int bound;

int block(int x) {
	return x / bl_len;
}

const int MAXK = 3000;

int bcnt[MAXK];
int tcnt[MAXK];
int st[MAXK], sptr;
map< int, int > free_cnt;
int gl_cnt[100500];
ve< ll > vans;

void sum_many(int x, int y, int cnt, ll &ans) {
	ans += 1ll * (x + y) * cnt;
	int z = x + y;
	if (z > bound) {
		free_cnt[z] += cnt;
	} else {
		bcnt[z] += cnt;
	}
}

ll get_ans() {
	memcpy(bcnt, tcnt, (bound + 1) * sizeof(bcnt[0]));
	free_cnt.clear();
	for (int i = 0; i < sptr; ++i) {
		free_cnt[gl_cnt[st[i]]]++;
	}
	ll ans = 0ll;
	int bad_ind = -1;
	for (int pos = 1; pos <= bound; ++pos) {
		int val = bcnt[pos];
		bcnt[pos] = 0;
		if (!val) continue;
		if (bad_ind != -1) {
			sum_many(bad_ind, pos, 1, ans);
			val--;
			bad_ind = -1;
		}
		if (val) {
			int gr = val / 2;
			val %= 2;
			if (gr) sum_many(pos, pos, gr, ans);
		}
		if (val) {
			bad_ind = pos;
		}
	}
	while (!free_cnt.empty()) {
		auto it = free_cnt.begin();
		pii pr = *it;
		free_cnt.erase(pr.fs);
		if (bad_ind != -1) {
			sum_many(bad_ind, pr.fs, 1, ans);
			pr.sc--;
			bad_ind = -1;
		}
		if (pr.sc) {
			int gr = pr.sc / 2;
			pr.sc %= 2;
			if (gr) {
				sum_many(pr.fs, pr.fs, gr, ans);
			}
		}
		if (pr.sc) {
			bad_ind = pr.fs;
		}
	}
	return ans;
}

void add_val(int c) {
	int cur_cnt = gl_cnt[c];
	if (cur_cnt <= bound) {
		tcnt[cur_cnt]--;
	}
	if (cur_cnt < bound) {
		tcnt[cur_cnt + 1]++;
	} else if (cur_cnt == bound) {
		st[sptr++] = c;
	}
	gl_cnt[c]++;
}

void erase_val(int c) {
	int cur_cnt = gl_cnt[c];
	if (cur_cnt == bound + 1) {
		--sptr;
		assert(st[sptr] == c);
		tcnt[cur_cnt - 1]++;
	} else if (cur_cnt <= bound) {
		tcnt[cur_cnt]--;
		tcnt[cur_cnt - 1]++;
	}
	gl_cnt[c]--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> q;
	l.resize(q);
	r = l;
	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i];
		--l[i], --r[i];
	}
	bound = int(sqrt(20. * n) + 1);
	bl_len = int(sqrt(2. * n) + 1);
	// bound = bl_len = 1;
	bl_cnt = (n + bl_len - 1) / bl_len;
	bl_len = (n + bl_cnt - 1) / bl_cnt;
	// cerr << bound << ' ' << bl_cnt << ' ' << bl_len << endl;
	ve< vpii > end_id(bl_cnt);
	vi single;
	for (int i = 0; i < q; ++i) {
		int from = block(l[i]), to = block(r[i]);
		// cerr << from << ' ' << to << endl;
		if (from == to) {
			single.pb(i);
		} else {
			end_id[from].pb(mp(to, i));
		}
	}
	for (auto &v: end_id) {
		sort(v.begin(), v.end());
	}
	vans.assign(q, 0ll);
	sptr = 0;
	memset(tcnt, 0, sizeof(tcnt));
	memset(gl_cnt, 0, sizeof(gl_cnt));
	for (int sid : single) {
		int lb = l[sid], rb = r[sid];
		for (int i = lb; i <= rb; ++i) {
			add_val(a[i]);
		}
		vans[sid] = get_ans();
		for (int i = lb; i <= rb; ++i) {
			erase_val(a[i]);
		}
	}
	for (int start = 0; start < bl_cnt; ++start) {
		memset(tcnt, 0, sizeof(tcnt));
		sptr = 0;
		memset(gl_cnt, 0, sizeof(gl_cnt));
		int rb = (start + 1) * bl_len;
		int ptr = 0;
		const auto &v = end_id[start];
		for (int en = start + 1; en < bl_cnt; ++en) {
			int lb = en * bl_len;
			while (ptr < sz(v) && v[ptr].fs == en) {
				int sid = v[ptr].sc;
				for (int i = l[sid]; i < rb; ++i) {
					add_val(a[i]);
				}
				for (int i = lb; i <= r[sid]; ++i) {
					add_val(a[i]);
				}
				vans[sid] = get_ans();
				for (int i = r[sid]; i >= lb; --i) {
					erase_val(a[i]);
				}
				for (int i = rb - 1; i >= l[sid]; --i) {
					erase_val(a[i]);
				}
				ptr++;
			}
			for (int i = lb; i < n && i < lb + bl_len; ++i) {
				add_val(a[i]);
			}
		}
	}
	for (auto &x : vans) {
		cout << x << '\n';
	}
	return 0;
}