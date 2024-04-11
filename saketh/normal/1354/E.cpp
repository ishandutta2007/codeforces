#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// {{{
struct union_find_bipartite {
    struct node {
        int parent;
        int size = 1, root_status = -1, same_as_root = 1;
        bool root_path_parity = 0, consistent = 1;
        node(int id) : parent(id) {}

        int choices() const {
            return !consistent ? 0 : root_status == -1 ? 2 : 1;
        }
        int minimum_size() const {
            if (root_status == 1) return same_as_root;
            else if (root_status == 0) return size - same_as_root;
            return min(same_as_root, size - same_as_root);
        }
    };
    vector<node> uf;
    int components, bipartite_components, rank, minimum_size;

    union_find_bipartite(int N = 0) : components(N), bipartite_components(N), rank(N), minimum_size(0) {
        for (int v = 0; v < N; v++) {
            uf.emplace_back(v);
        }
    }

    int rep(int u) {
        if (uf[u].parent == u) return u;
        int root = rep(uf[u].parent);
        uf[u].root_path_parity ^= uf[uf[u].parent].root_path_parity;
        return uf[u].parent = root;
    }

    void subtract_component(int u) {
        components--;
        if (uf[u].consistent) {
            bipartite_components--;
            rank -= uf[u].root_status == -1;
            minimum_size -= uf[u].minimum_size();
        }
    }

    void add_component(int u) {
        components++;
        if (uf[u].consistent) {
            bipartite_components++;
            rank += uf[u].root_status == -1;
            minimum_size += uf[u].minimum_size();
        }
    }

    bool set_status(int u, bool u_status) {
        int u_root = rep(u);
        subtract_component(u_root);

        const bool implied_root_status = u_status ^ uf[u].root_path_parity;
        if (uf[u_root].root_status == -1) {
            uf[u_root].root_status = implied_root_status;
        } else if (uf[u_root].root_status != implied_root_status) {
            uf[u_root].consistent = false;
        }

        add_component(u_root);
        return uf[u_root].consistent;
    }

    struct result { bool added_connectivity, is_consistent; };
    result unite(int u, int v, bool edge_parity) {
        int u_root = rep(u), v_root = rep(v);
        if (u_root == v_root) {
            subtract_component(u_root);
            if (edge_parity != (uf[u].root_path_parity ^ uf[v].root_path_parity)) {
                uf[u_root].consistent = false;
            }
            add_component(u_root);
            return {false, uf[u_root].consistent};
        }

        edge_parity ^= uf[u].root_path_parity ^ uf[v].root_path_parity;
        u = u_root;
        v = v_root;
        if (uf[u].size < uf[v].size)
            swap(u, v);

        subtract_component(u), subtract_component(v);

        uf[v].parent = u;
        uf[v].root_path_parity = edge_parity;
        uf[u].size += uf[v].size;
        uf[u].consistent &= uf[v].consistent;

        if (edge_parity)
            uf[u].same_as_root += uf[v].size - uf[v].same_as_root;
        else
            uf[u].same_as_root += uf[v].same_as_root;

        if (uf[v].root_status != -1) {
            bool implied_u_status = uf[v].root_status ^ edge_parity;
            uf[u].consistent &= (uf[u].root_status == -1 || uf[u].root_status == implied_u_status);
            uf[u].root_status = implied_u_status;
        }

        add_component(u);
        return {true, uf[u].consistent};
    }
    result constrain_to_be_same     (int u, int v) { return unite(u, v, 0); }
    result constrain_to_be_different(int u, int v) { return unite(u, v, 1); }

    // check consistency without recording constraint
    bool is_consistent(int u, bool u_status) {
        int u_root = rep(u);
        if (!uf[u_root].consistent) return false;
        if (uf[u_root].root_status == -1) return true;
        return u_status == (uf[u].root_path_parity ^ uf[u_root].root_status);
    }
    // check consistency of resulting component without recording constraint
    bool is_consistent(int u, int v, bool edge_parity) {
        int u_root = rep(u), v_root = rep(v);
        if (!uf[u_root].consistent || !uf[v_root].consistent) {
            return false;
        } else if (u_root == v_root) {
            return edge_parity == (uf[u].root_path_parity ^ uf[v].root_path_parity);
        } else if (uf[u_root].root_status == -1 || uf[v_root].root_status == -1) {
            return true;
        } else {
            return (uf[u].root_path_parity ^ uf[u_root].root_status
                  ^ uf[v].root_path_parity ^ uf[v_root].root_status) == edge_parity;
        }
    }
};
// }}}

int main() {
    setIO();

	int N, M; re(N, M);
	int n1, n2, n3; re(n1, n2, n3);

	array<int, 4> exp = { 0, n1, n2, n3 };

	union_find_bipartite ufb(N);

	vpii edges;

	bool ok = 1;
	F0R (i, M) {
		int u, v; re(u, v); --u, --v;
		edges.eb(u, v);
		ok &= ufb.constrain_to_be_different(u, v).is_consistent;
	}

	if (!ok) {
		ps("NO");
		return 0;
	}

	vector<array<vi, 2>> comps(N);
	{
		F0R (i, N) {
			int p = ufb.rep(i);
			comps[p][ufb.uf[i].root_path_parity].pb(i);
		}

		decltype(comps) tmp;
		trav (e, comps) {
			if (!e[0].empty() || !e[1].empty())
				tmp.pb(e);
		}
		comps = tmp;
	}

	int C = sz(comps);
	// -1 = can't make, 0 = make by assign as-is, 1 = make by assign flipped
	vvi dp(C + 1, vi(N + 1, -1));

	dp[0][0] = 0;
	F0R (i, C) {
		F0R (ct2, N + 1) if (dp[i][ct2] != -1) {
			dp[i+1][ct2 + sz(comps[i][0])] = 0;
			dp[i+1][ct2 + sz(comps[i][1])] = 1;
		}
	}

	if (dp[C][n2] == -1) {
		ps("NO");
		return 0;
	}
	ps("YES");

	vi assign(N);

	int tmp = n2;
	FORd (i, 1, C + 1) {
		int inx = dp[i][tmp];
		trav (e, comps[i-1][inx]) {
			assign[e] = 2;
			tmp--;
		}
	}

	trav (e, assign) {
		if (e == 2) continue;
		if (n1 > 0) { e = 1; n1--; }
		else { e = 3; n3--; }
	}

	array<int, 4> ct = {0,0,0,0};
	trav (e, assign) ct[e]++;
	assert(ct == exp);
	trav (p, edges) {
		assert(abs(assign[p.f] - assign[p.s]) == 1);
	}

	trav (e, assign)
		pr(e);
	ps();

    return 0;
}