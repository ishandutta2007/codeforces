#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = (int)1e5 + 31, Log = 20;
const ll Mod[2] = {(ll)1e9 + 7, (ll)1e9 + 9};

ll pow2[2][N];
struct Val {
	bool all; ll hash[2];
	Val(bool a = false, ll h0 = 0, ll h1 = 0) {
		all = a; hash[0] = h0; hash[1] = h1;
	}
	Val add(Val v, int l) {
		Val r; r.all = all & v.all;
		r.hash[0] = (v.hash[0] * pow2[0][l] + hash[0]) % Mod[0];
		r.hash[1] = (v.hash[1] * pow2[1][l] + hash[1]) % Mod[1];
		return r;
	}
};

#define m ((l + r) / 2)
struct PST {
	Val v; PST *lc, *rc;
	static int n;
	static PST mem[];
	#define NEW(arg...) (new(mem + ++n)PST(arg))
	PST() {}
	PST(Val v) : v(v), lc(mem), rc(mem) {}
	PST(Val v, PST *lc, PST *rc) : v(v), lc(lc), rc(rc) {}

	bool all(int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return v.all;
		if(qr <= m) return lc -> all(l, m, ql, qr);
		if(ql >= m) return rc -> all(m, r, ql, qr);
		return (lc -> all(l, m, ql, m)) & (rc -> all(m, r, m, qr));
	}
	PST* zero(int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return NEW(Val());
		if(qr <= m) {
			PST* nlc = lc -> zero(l, m, ql, qr);
			return NEW(nlc -> v.add(rc -> v, m - l), nlc, rc);
		} else if(ql >= m) {
			PST *nrc = rc -> zero(m, r, ql, qr);
			return NEW(lc -> v.add(nrc -> v, m - l), lc, nrc);
		} else {
			PST* nlc = lc -> zero(l, m, ql, m);
			PST* nrc = rc -> zero(m, r, m, qr);
			return NEW(nlc -> v.add(nrc -> v, m - l), nlc, nrc);
		}
	}
	PST* one(int l, int r, int p) {
		if(l + 1 == r) return NEW(Val(true, 1, 1));
		if(p < m) {
			PST* nlc = lc -> one(l, m, p);
			return NEW(nlc -> v.add(rc -> v, m - l), nlc, rc);
		} else {
			PST *nrc = rc -> one(m, r, p);
			return NEW(lc -> v.add(nrc -> v, m - l), lc, nrc);
		}
	}
	PST* add(int p) {
		if(!all(0, N, p, p + 1))
			return one(0, N, p);
		int left = p, right = N - 1;
		while(left + 1 < right) {
			int mid = (left + right) / 2;
			if(all(0, N, p, mid + 1))
				left = mid;
			else right = mid;
		}
		return zero(0, N, p, left + 1) -> one(0, N, left + 1);
	}
};
bool cmp(PST *p, PST *q, int l, int r) {
	if(l + 1 == r)
		return p -> v.hash[0] < q -> v.hash[0];
	if(p -> v.hash[0] == q -> v.hash[0] &&
		p -> v.hash[1] == q -> v.hash[1])
		return false;
	if(p -> rc -> v.hash[0] == q -> rc -> v.hash[0] &&
		p -> rc -> v.hash[1] == q -> rc -> v.hash[1])
		return cmp(p -> lc, q -> lc, l, m);
	return cmp(p -> rc, q -> rc, m, r);
}
#undef m

int PST :: n = 0;
PST PST :: mem[N * Log * 8] = {{Val()}};

struct PQ_Val {
	PST *p; int id;
	bool operator <(PQ_Val v) const {
		if(cmp(p, v.p, 0, N)) return true;
		if(cmp(v.p, p, 0, N)) return false;
		return id < v.id;
	}
};

int p[N];
vector <pair <int, int>> e[N];
PST* f[N];

int main() {
	for(int t = 0; t < 2; t ++) {
		pow2[t][0] = 1;
		for(int i = 1; i < N; i ++)
			pow2[t][i] = pow2[t][i - 1] * 2 % Mod[t];
	}
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	int s, t; cin >> s >> t;
	fill(f + 1, f + n + 1, &(PST :: mem[0]));
	for(int i = 1; i <= n; i ++) if(i != s)
		f[i] = f[i] -> add(N - 1);

	set <PQ_Val> pq;
	for(int i = 1; i <= n; i ++)
		pq.insert({f[i], i});
	
	while(!pq.empty()) {
		int u = pq.begin() -> id; pq.erase(pq.begin());
		for(auto i : e[u]) {
			int v = i.first, w = i.second;
			PST *upd = f[u] -> add(w);
			if(cmp(upd, f[v], 0, N)) {
				p[v] = u;
				pq.erase({f[v], v});
				f[v] = upd;
				pq.insert({f[v], v});
			}
		}
	}
	
	if(p[t] || s == t) {
		cout << f[t] -> v.hash[0] << '\n';
		vector <int> ans;
		for(int i = t; ; i = p[i]) {
			ans.push_back(i);
			if(i == s) break;
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for(int x : ans) cout << x << ' ';
		cout << '\n';
	} else
		cout << -1 << '\n';

	return 0;
}