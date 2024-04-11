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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto pref = [](int lim) {
        if (lim == 0) return 0ll;
        int last_even = lim/2 * 2;
        int last_odd = lim - (lim == last_even);

        ll odd_sum = (last_odd+1)/2;
        odd_sum *= odd_sum;

        ll even_sum = (last_even/2) * 1ll * (last_even/2 + 1);
        return even_sum - odd_sum;
    };

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        cout << pref(r) - pref(l-1) << "\n";
    }

    return 0;
}