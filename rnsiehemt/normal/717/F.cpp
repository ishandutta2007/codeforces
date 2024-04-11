#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int Max = 1<<18, MaxNodes = 1<<19;

#define lc (n*2+1)
#define rc (n*2+2)
#define nm ((nl+nr)/2)

std::vector<ll> mins0, mins1, sums;

struct rt_t {
    ll lazy[MaxNodes];
    ll sum[MaxNodes];
    ll min0[MaxNodes];
    ll min1[MaxNodes];
    void unlazy(int n, int nl, int nr) {
        ll &k = lazy[n];
        if (k) {
            if (nl+1 == nr) {
                // single node
                if (nl&1) {
                    sum[n] -= k;
                    min1[n] += k;
                } else {
                    sum[n] += k;
                    min0[n] += k;
                }
            } else {
                min0[n] += k;
                lazy[lc] += k;
                lazy[rc] += k;
            }
            k = 0;
        }
    }
    void u(int n, int nl, int nr, int ul, int ur, ll uv) {
        unlazy(n, nl, nr);
        if (ul <= nl && nr <= ur) {
            lazy[n] += uv;
        } else {
            if (ul < nm) u(lc, nl, nm, ul, ur, uv);
            if (nm < ur) u(rc, nm, nr, ul, ur, uv);
            unlazy(lc, nl, nm);
            unlazy(rc, nm, nr);
            sum[n] = sum[lc] + sum[rc];
            min0[n] = std::min(min0[lc], sum[lc] + min0[rc]);
            min1[n] = std::min(min1[lc], -sum[lc] + min1[rc]);
        }
    }
    void query(int n, int nl, int nr, int ql, int qr) {
        unlazy(n, nl, nr);
        if (ql <= nl && nr <= qr) {
            mins0.pb(min0[n]);
            mins1.pb(min1[n]);
            sums.pb(sum[n]);
        } else {
            if (ql < nm) query(lc, nl, nm, ql, qr);
            if (nm < qr) query(rc, nm, nr, ql, qr);
        }
    }
} rt;

int solve(int ql, int qr) {
    sums.clear();
    mins0.clear();
    mins1.clear();
    rt.query(0, 0, Max, ql, qr);
    ll s = 0;
    for (int i = 0; i < sz(sums); i++) {
        if (s + mins0[i] < 0) return 0;
        if (-s + mins1[i] < 0) return 0;
        s += sums[i];
    }
    return s ? 0 : 1;
}

int n, q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll a; scanf("%lld", &a);
        rt.u(0, 0, Max, i, i+1, a-1);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int c, a, b; scanf("%d%d%d", &c, &a, &b); b++;
        if (c == 1) {
            ll k; scanf("%lld", &k);
            rt.u(0, 0, Max, a, b, k);
        } else printf("%d\n", solve(a, b));
    }
}