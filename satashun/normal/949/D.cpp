//
// Created by  on 2019/11/11.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i,0,n)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template<class T, class U>
void chmin(T &t, const U &u) { if (t > u) t = u; }

template<class T, class U>
void chmax(T &t, const U &u) { if (t < u) t = u; }

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

int main() {
    int n;
    ll d, b;
    cin >> n >> d >> b;
    V<ll> a(n);
    rep(i, n) cin >> a[i];
    int lo = 0, hi = n * b + 1;
    int ans = n;

    auto calc = [&](ll m) {
        int ansl = 0, ansr = 0;

        {
            V<ll> vec = a;
            V<ll> ps(n + 1);
            ll cs = 0;
            rep(i, n) {
                ll zan = min(m - cs, vec[i]);
                vec[i] = zan;
                ps[i + 1] = ps[i] + vec[i];
                cs += vec[i];
            }

            int nl = (n + 1) / 2;
            ll rem = 0;
            rep(i, nl) {
                ll cur = vec[i] + rem;
                if (cur >= b) {
                    rem = cur - b;
                } else {
                    ll r = min<ll>(i + d * (i + 1) + 1, n);
                    ll fr = ps[r] - ps[i];
                    cur = fr + rem;
                    rem += vec[i];
                    if (cur >= b) {
                        rem -= b;
                    } else {
                        ansl++;
                    }
                }
            }
        }

        {
            V<ll> vec = a;
            reverse(ALL(vec));
            ll mm = n * b - m;
            int nr = n / 2;

            V<ll> ps(n + 1);
            rep(i, n) ps[i + 1] = ps[i] + vec[i];
            ll cs = 0;
            rep(i, n) {
                ll zan = min(mm - cs, vec[i]);
                vec[i] = zan;
                ps[i + 1] = ps[i] + vec[i];
                cs += vec[i];
            }

            ll rem = 0;
            rep(i, nr) {
                ll cur = vec[i] + rem;
                if (cur >= b) {
                    rem = cur - b;
                } else {
                    ll r = min<ll>(i + d * (i + 1) + 1, n);
                    ll fr = ps[r] - ps[i];
                    cur = fr + rem;
                    rem += vec[i];
                    if (cur >= b) {
                        rem -= b;
                    } else {
                        ansr++;
                    }
                }
            }
        }
        return mp(ansl, ansr);
    };

    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        auto res = calc(m);
        int ansl = res.fi, ansr = res.se;
        chmin(ans, max(ansl, ansr));
        if (ansl >= ansr) {
            lo = m;
        } else {
            hi = m;
        }
    }
    if (lo > 0) {
        auto res = calc(lo - 1);
        int ansl = res.fi, ansr = res.se;
        chmin(ans, max(ansl, ansr));
    }
    if (hi <= n * b) {
        auto res = calc(hi);
        int ansl = res.fi, ansr = res.se;
        chmin(ans, max(ansl, ansr));
    }
    cout << ans << endl;

    return 0;
}