#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k) {
        for(i++; i <= S; i += i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i -= i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }

    int lower_bound(T sum) {
        T res = 0;
        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            if ((inx + (1 << i) <= S) && res + v[inx + (1 << i)] < sum) {
                inx += 1 << i;
                res += v[inx];
            }
        }
        return inx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    ll T;
    cin >> N >> T;

    vi cook(N), eat(N), par(N), arc(N);
    vvi ch(N);

    for (int i = 0; i < N; i++) {
        cin >> cook[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> eat[i];
    }

    for (int i = 1; i < N; i++) {
        cin >> par[i];
        ch[--par[i]].push_back(i);
        cin >> arc[i];
    }

    const int MAXV = 1e6 + 1;
    BIT<ll> ct(MAXV), tot(MAXV);

    vll val(N);
    function<void(int, ll)> calc_val = [&](int loc, ll V) {
        ct.update(eat[loc], cook[loc]);
        tot.update(eat[loc], eat[loc] * 1ll * cook[loc]);

        V -= 2 * arc[loc];

        int lv = tot.lower_bound(V);
        if (lv) {
            val[loc] = ct.read(lv - 1);
            if (lv < MAXV) val[loc] +=
                min((V - tot.read(lv - 1)) / lv, ct.read(lv, lv));
        }

        for (int blw : ch[loc])
            calc_val(blw, V);

        ct.update(eat[loc], -cook[loc]);
        tot.update(eat[loc], -eat[loc] * 1ll * cook[loc]);
    };
    calc_val(0, T);

    vll ans(N);
    function<ll(int)> calc_ans = [&](int loc) {
        ll mx1 = 0, mx2 = 0;
        for (int blw : ch[loc]) {
            ll cres = calc_ans(blw);
            if (cres >= mx1) {
                mx2 = mx1;
                mx1 = cres;
            } else if (cres > mx2) {
                mx2 = cres;
            }
        }
        return ans[loc] = max(val[loc], loc ? mx2 : mx1);
    };
    cout << calc_ans(0) << "\n";

    return 0;
}