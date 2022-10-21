#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
 
namespace FIO {
	inline char gc() {
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}
	template <class T> inline int read(T &x) {
		char c = gc(), b = 1;
		for (; !(c >= '0' && c <= '9' || c == EOF); c = gc()) if (c == '-') b = -b;
		if (c == EOF) return 0;
		for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = gc());
		x *= b;
		return 1;
	}
	inline int read(char *s) {
		char c = gc();
		int len = 0;
		for (; c <= ' ' && c != EOF; c = gc());
		if (c == EOF) return 0;
		for (; !(c <= ' '); s[len++] = c, c = gc());
		s[len] = 0;
		return 1;
	}
	template <typename Head, typename... Tail>
	inline int read(Head& H, Tail&... T) {
		int rlt = read(H);
		return rlt + read(T...);
	}
	inline void pc(char c) {
		static char buf[100000], *p1 = buf, *p2 = buf + 100000;
		if (!c) fwrite(buf, 1, p1 - buf, stdout), p1 = buf;
		else {
			*p1++ = c;
			p1 == p2&&(fwrite(buf, 1, 100000, stdout), p1 = buf);
		}
	}
	template <class T> inline void write(T x) {
		static char str[64];
		if (x == 0) pc('0');
		else {
			if (x < 0) pc('-'), x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i --) pc(str[i]);
		}
	}
	inline void write(char c) {
		pc(c);
	}
	inline void write(char *s) {
		for (int i = 0; s[i]; i ++) pc(s[i]);
	}
	inline void write(const char *s) {
		for (int i = 0; s[i]; i ++) pc(s[i]);
	}
	template <typename Head, typename... Tail>
	inline void write(Head H, Tail... T) {
		write(H), write(T...);
	}
	inline void flush() {
		pc(0);
	}
}
using namespace FIO;
 
using namespace std;
 
const int N = 600500;
const int inf = 1e9 + 50;
const int mod = 998244353;
 
int n, q;
int a[N], t[N], l[N], r[N], d[N];
 
vector<int> x;
 
int ID(int u) {
    return lower_bound(x.begin(), x.end(), u) - x.begin();
}
 
const int D = 25;
 
int h[N][D];
 
struct segtree {
    int vol;
    vector<int> member, sum, pos;
    segtree (int vol = 0) : vol(vol) {
        sum.resize(vol << 2);
    }
    void push_up(int k) {
        sum[k] = sum[k << 1] + sum[k << 1 ^ 1];
        return;
    }
    void resize(int n) {
        vol = n;
        sum.resize(vol << 2);
        pos.resize(vol + 1);
        build();
    }
    void build() {build(1, vol, 1);}
    void build(int l, int r, int k) {
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, k << 1);
        build(m + 1, r, k << 1 ^ 1);
        push_up(k);
        return;
    }
    void update(int p, int d) {
        int l = 1, r = vol, k = 1;
        while(l < r) {
            int m = l + r >> 1;
            if(p <= m) r = m, k = k << 1;
            else l = m + 1, k = k << 1 ^ 1;
        }
        sum[k] = d;
        while(k > 1) {
            k >>= 1;
            push_up(k);
        }
        return;
    }
    int query(int l, int r, int k, int L, int R) {
        if(L <= l && r <= R) return sum[k];
        if(R < l || r < L) return 0;
        int m = l + r >> 1;
        return query(l, m, k << 1, L, R) + query(m + 1, r, k << 1 ^ 1, L, R);
    }
    int query(int l, int r) {
        return query(1, vol, 1, l, r);
    }
};
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void pre_hash() {
    for(int i = 0; i < N; i ++) for(int j = 0; j < D; j ++) h[i][j] = rng() % 3000 + 1;
}
 
int main() {
    pre_hash();
    read(n, q);
    for(int i = 1; i <= n; i ++) read(a[i]), x.push_back(a[i]);
    for(int i = 1; i <= q; i ++) {
        read(t[i], l[i], r[i]);
        if(t[i] == 2) read(d[i]);
        else x.push_back(r[i]);
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for(int i = 1; i <= n; i ++) a[i] = ID(a[i]);
    for(int i = 1; i <= q; i ++) if(t[i] == 1) r[i] = ID(r[i]);
    segtree S[D];
    for(int i = 0; i < D; i ++) S[i].resize(n);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < D; j ++) S[j].update(i, h[a[i]][j]);
    }
    for(int i = 1; i <= q; i ++) {
        if(t[i] == 1) {
            for(int j = 0; j < D; j ++) S[j].update(l[i], h[r[i]][j]);
        }
        else {
            bool ok = 1;
            if((r[i] - l[i] + 1) % d[i]) ok = 0;
            if(d[i] > 1) {
                for(int j = 0; j < D && ok; j ++) if(S[j].query(l[i], r[i]) % d[i]) ok = 0;
            }
            write(ok ? "YES\n" : "NO\n");
        }
    }
    flush();
    return 0;
}