#include <bits/stdc++.h>
// #include <atcoder/all>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

template <typename T>
struct BIT {
private:
    int n;
    vector<T> dat;  // 1-indexed

public:
    BIT(vector<T> v) : n(v.size() - 1) {
        dat = v;
        for(int i = 1; i < n; i++)
            if(i + (i & -i) <= n) dat[i + (i & -i)] += dat[i];
    }
    BIT(int n) : n(n) { dat.assign(n + 1, 0); }
    void add(int k, T a) {
        while(k <= n) {
            dat[k] += a;
            k += k & -k;
        }
    }
    T sum(int a) {
        T ret = 0;
        while(a) {
            ret += dat[a];
            a -= a & -a;
        }
        return ret;
    }
    T sum(int a, int b) { return sum(b) - sum(a - 1); }
    int lowerBound(int w) {
        if(w <= 0) return 0;
        int x = 0;
        for(int k = 1 << int(log2(n)); k; k /= 2) {
            if(x + k <= n && dat[x + k] < w) {
                x += k;
                w -= dat[x];
            }
        }
        return x + 1;
    }
};

ll n, m, q;
ll cnt[500009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;
    rep(i, n) {
        ll a;
        cin >> a;
        cnt[a]++;
    }

    vector<ll> p(m);
    iota(ALL(p), 1);
    sort(ALL(p), [&](ll i, ll j) {
        return make_pair(cnt[i], i) < make_pair(cnt[j], j);
    });

    vector<ll> sum;
    sum.push_back(n);
    FOR(i, 1, m)
    sum.push_back(sum.back() + i * (cnt[p[i]] - cnt[p[i - 1]]));

    vector<pair<ll, ll>> qs;
    rep(i, q) {
        ll k;
        cin >> k;
        qs.emplace_back(k, i);
    }
    sort(ALL(qs));

    vector<ll> ans(q);

    BIT<int> bit(m);

    int j = 0;
    for(auto [k, id] : qs) {
        k--;
        while(j < sum.size() && sum[j] <= k) {
            bit.add(p[j], 1);
            j++;
        }
        k -= sum[j - 1];
        ans[id] = bit.lowerBound(k % j + 1);
    }

    rep(i, q) cout << ans[i] << endl;

    return 0;
}