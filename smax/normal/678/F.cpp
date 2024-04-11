#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
using ll = long long;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

LineContainer st[1200005];

void insert(int p, int l, int r, int i, int j, int a, int b) {
    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        st[p].add(a, b);
        return;
    }
    int m = (l + r) / 2;
    insert(2 * p, l, m, i, j, a, b);
    insert(2 * p + 1, m + 1, r, i, j, a, b);
}

long long query(int p, int l, int r, int i, int x) {
    long long ret = st[p].empty() ? LLONG_MIN : st[p].query(x);
    if (l == r)
        return ret;
    int m = (l + r) / 2;
    if (i <= m)
        return max(ret, query(2 * p, l, m, i, x));
    else
        return max(ret, query(2 * p + 1, m + 1, r, i, x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> type(n), nd(n, n - 1), queries(n);
    vector<pair<int, int>> lines(n);
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        type[i] = t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            lines[i] = {a, b};
        } else if (t == 2) {
            int j;
            cin >> j;
            j--;
            nd[j] = i - 1;
        } else {
            int q;
            cin >> q;
            queries[i] = q;
        }
    }

    for (int i=0; i<n; i++) {
        if (type[i] == 1) {
            insert(1, 0, n - 1, i, nd[i], lines[i].first, lines[i].second);
        } else if (type[i] == 3) {
            long long ret = query(1, 0, n - 1, i, queries[i]);
            if (ret == LLONG_MIN)
                cout << "EMPTY SET\n";
            else
                cout << ret << "\n";
        }
    }

    return 0;
}