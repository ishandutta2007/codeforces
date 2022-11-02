#include <bits/stdc++.h>
using namespace std;

void debug() { cerr << endl; }

template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << H << ' ';
	debug(T...);
}

#define N 1000100

int n, q;

int pw1[N], pw2[N];
const int base1 = 731, base2 = 4321, mod1 = 998244353, mod2 = 1e9 + 9;

struct Hash{
	int val1, val2;
	Hash(int v1 = 0) : val1(v1), val2(v1) {}
	Hash(int v1, int v2) : val1(v1), val2(v2) {}
	Hash operator + (const Hash &h) const {
		return Hash((val1 + h.val1) % mod1, (val2 + h.val2) % mod2);
	}
	Hash operator + (const int x) const {
		return (*this) + Hash(x);
	}
	Hash operator * (const int x) const {
		return Hash(1ll * val1 * pw1[x] % mod1, 1ll * val2 * pw2[x] % mod2);
	}
	bool operator == (const Hash &h) const {
		return val1 == h.val1 && val2 == h.val2;
	}
	bool operator != (const Hash &h) const {
		return !((*this) == h);
	}
} pre[N], suf[N];

char s[N], t[N], p[N];

int h[N], f[N];
void prepare(char *p, int *h) {
    int m = strlen(p + 1);
    h[1] = 0;
    for (int i = 2, j = 0; i <= m; i ++) {
        while (j && p[j + 1] != p[i]) j = h[j];
        if (p[j + 1] == p[i]) j ++;
        h[i] = j;
    }
    return;
}
void kmp_matching(char *t, char *p, int *h, int *f) {
    int n = strlen(t), m = strlen(p + 1);
    for (int i = 0, j = 0; i < n; i ++) {
        while (j && t[i] != p[j + 1]) j = h[j];
        if (t[i] == p[j + 1]) j ++;
        f[i] = j;
        if (j == m) j = h[m];
    }
    return;
}

string tmp;
Hash _pre[N], _suf[N];
int cnt[N][26];

int pw[N], inv[N];
const int mod = 1e9 + 7;

int h1[N], f1[N];

int main() {
    pw1[0] = pw2[0] = 1, pw[0] = inv[0] = 1;
    for (int i = 1; i < N; i ++) pw1[i] = 1ll * pw1[i-1] * base1 % mod1, pw2[i] = 1ll * pw2[i-1] * base2 % mod2;
    for (int i = 1; i < N; i ++) pw[i] = 2 * pw[i-1] % mod, inv[i] = 1ll * inv[i-1] * (mod + 1 >> 1) % mod;
    scanf("%d %d", &n, &q);
    scanf("%s %s", p + 1, s);
    prepare(p, h);
    int UP = N, len = strlen(p + 1);
    if (n < 20) UP = min(UP, 1 << n);
    for (int i = 1; i < UP; i ++) pre[i] = pre[i-1] * 1 + s[__builtin_ctz(i)], suf[i] = suf[i-1] + Hash(s[__builtin_ctz(-i)]) * (i - 1);
    for (int i = UP; i < N; i ++) pre[i] = suf[i] = Hash(-1);
    for (int i = n - 1; i >= 0; i --) {
		memcpy(cnt[i], cnt[i+1], 26 << 2);
		if ((cnt[i][s[i]-'a'] += inv[i]) >= mod) cnt[i][s[i]-'a'] -= mod;
    }
    while (q --) {
		int upk;
		scanf("%d %s", &upk, t);
		int m = strlen(t);
		kmp_matching(t, p, h, f);
		int ans = 0;
		if (m <= len) {
			prepare(t - 1, h1), kmp_matching(p + 1, t - 1, h1, f1);
			int cnt = 0;
			for (int i = 0; i < len; i ++) if (f1[i] == m) cnt ++;
			ans = 1ll * cnt * pw[upk] % mod;
		}
		Hash rel, cur;
		for (int i = 0; i <= len && i < m; rel = rel + Hash(p[len-i]) * i, cur = cur * 1 + t[i], i ++) {
			if (rel == cur) {
				bool fg = true;
				int j; tmp.clear();
				for (j = i; j + len + 1 < m; j += len + 1) {
					tmp += t[j];
					if (f[j+len] != len) {
						fg = false;
						break;
					}
				}
				if (!fg) continue;
				tmp += t[j];
				for (int k = 1; j + k < m; k ++) {
					if (p[k] != t[j+k]) {
						fg = false;
						break;
					}
				}
				if (!fg) continue;
				int L = tmp.length();
				for (int j = 1; j < L; j ++) {
					_pre[j] = _pre[j-1] * 1 + tmp[j-1];
				}
				_suf[L-1] = Hash();
				for (int j = L - 2; j >= 0; j --) {
					_suf[j] = _suf[j+1] + Hash(tmp[j+1]) * (L - 2 - j);
				}
				for (int j = 0; j < L; j ++) {
					if (_pre[j] == suf[j] && _suf[j] == pre[L-1-j]) {
						int c = max(j > 0 ? __lg(j) : -1, j < L - 1 ? __lg(L-1-j) : -1);
						c ++;
						if (c <= upk - 1) {
							ans = (ans + 1ll * (cnt[c][tmp[j]-'a'] - cnt[upk][tmp[j]-'a']) * pw[upk-1]) % mod;
							if (ans < 0) ans += mod;
						}
					}
				}
			}
		}
		printf("%d\n", ans);

    }

    return 0;
}