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

const ll MOD = 998244353;

struct NumberTheoreticTransform {
    int mod;
    int root;

    NumberTheoreticTransform(int mod, int root) : mod(mod), root(root) {}

    int mul(int x, int y) {
        return int64_t(x) * y % mod;
    }

    int add(int x, int y) {
        return (x += y) >= mod ? x - mod : x;
    }

    int pow(int x, int y) {
        int res = 1;
        while (y > 0) {
            if (y & 1) res = mul(res, x);
            x = mul(x, x);
            y >>= 1;
        }
        return res;
    }

    int inv(int x) {
        return pow(x, mod - 2);
    }

    void ntt(std::vector<int> &a, bool rev = false) {
        int n = a.size();
        int h = 0;
        for (int i = 0; 1 << i < n; i++) h++;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (int k = 0; k < h; k++) {
            	j |= (i >> k & 1) << (h - 1 - k);
            }
            if (i < j) std::swap(a[i], a[j]);
        }
        for (int i = 1; i < n; i *= 2) {
            int w = pow(root, (mod - 1) / (i * 2));
            if (rev) w = inv(w);
            for (int j = 0; j < n; j += i * 2) {
                int wn = 1;
                for (int k = 0; k < i; k++) {
                    int s = a[j + k + 0];
                    int t = mul(a[j + k + i], wn);
                    a[j + k + 0] = add(s, t);
                    a[j + k + i] = add(s, mod - t);
                    wn = mul(wn, w);
                }
            }
        }
        int v = inv(n);
        if (rev) for (int i = 0; i < n; i++) a[i] = mul(a[i], v);
    }

    std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
        int s = a.size() + b.size() - 1;
        int t = 1;
        while (t < s) t *= 2;
        a.resize(t);
        b.resize(t);
        ntt(a);
        ntt(b);
        for (int i = 0; i < t; i++) {
            a[i] = mul(a[i], b[i]);
        }
        ntt(a, true);

        a.resize(s);
        return a;
    }
};

const int maxn = 100010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[maxn];
	int n;

public:
	BIT() {
		n = maxn;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		++i;
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		++i;
		while (i < n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

const int MX = 4010;
ll inv[MX], fact[MX], ifact[MX];

void init()
{
    inv[1] = 1;
    for (int i = 2; i < MX; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MX; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        ifact[i] = ifact[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

const int MN = 2010;
int a[MN][MN];
ll sub[MN][MN];
ll pw[MN];

int main() {
	init();
	NumberTheoreticTransform ntt(998244353, 5);

	rep(i, MN) {
		vi va(i + 1), vb(i + 1);
		for (int j = 0; j <= i; ++j) {
			va[j] = ifact[j] * fact[i - j] % MOD;
			if (j % 2 == 1) {
				va[j] = -va[j];
				if (va[j] < 0) va[j] += MOD;
			}
		}

		for (int j = 0; j <= i; ++j) {
			vb[j] = ifact[j] % MOD;
		}

		va = ntt.mul(va, vb);

		for (int j = 0; j <= i; ++j) {
			sub[i][j] = va[j] * fact[j] % MOD;
		}
	}

	int n; scanf("%d", &n);
	rep(i, n) {
		rep(j, n) {
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}

	pw[0] = 1;
	rep(i, MN-1) {
		pw[i+1] = pw[i] * sub[n][n] % MOD;
	}

	ll ans = 0;

	vi ng(n, -1);

	rep(r, n) {
		BIT<int> T, Tcan;
		vi ban(n), can(n);

		int cnt = 0;
		int pos = 0;

		for (int c = n-1; c >= 0; --c) { //smaller
			if (ban[a[r][c]]) {
				T.add(a[r][c], 1);
				++pos;
			}
			Tcan.add(a[r][c], 1);
			can[a[r][c]] = true;

			ll all = Tcan.sum(a[r][c] - 1);
			ll both = T.sum(a[r][c] - 1);

			if (ng[c] < a[r][c] && can[ng[c]]) {
				--all;
				if (ban[ng[c]]) {
					--both;
				}
			}

			ll ad = (sub[n-1-c][pos] * (all - both) + sub[n-1-c][pos-1] * both) % MOD * pw[n-1-r] % MOD;

			ans = (ans + ad) % MOD;

			if (ng[c] != -1) {
				ban[ng[c]] = true;
				if (can[ng[c]]) {
					T.add(ng[c], 1);
					++pos;
				}
			}
		}

		rep(c, n) ng[c] = a[r][c];
	}

	cout << ans << endl;

	return 0;
}