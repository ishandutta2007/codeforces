#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll A[MAXN], ps[MAXN], n, ans, max_delta;

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
} cht;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	cht.add(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		ans += A[i] * i;

		max_delta = max(max_delta, cht.query(A[i]) + ps[i - 1] - i * A[i]);	
		cht.add(i + 1, -ps[i]);
	}

	cht.clear();
	for (int i = n; i > 0; i--) {
		cht.add(i, -ps[i]);
		max_delta = max(max_delta, cht.query(A[i]) - i * A[i] + ps[i]);
	}

	cout << ans + max_delta << endl;
	return 0;
}