#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <typename T> struct BIT {
  private:
    int n;
    vector<T> dat; // 1-indexed

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    BIT<int> bit(n);

    rep(i, n) {
        int x;
        cin >> x;
        bit.add(x, 1);
    }

    rep(_, q) {
        int x;
        cin >> x;
        if(1 <= x) bit.add(x, 1);
        if(x < 0) bit.add(bit.lowerBound(-x), -1);
    }

    if(bit.sum(n) == 0)
        cout << 0 << endl;
    else
        cout << bit.lowerBound(1) << endl;

    return 0;
}