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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    cin >> N >> X;

    vi vals(N);
    vi first(X + 1, -1), last(X + 1, -1);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        if (first[vals[i]] == -1)
            first[vals[i]] = i;
        last[vals[i]] = i;
    }

    vi pref(X + 1, -1);
    pref[0] = 0;
    for (int v = 1; v <= X; v++) {
        if (first[v] != -1) {
            if (first[v] < pref[v-1]) break;
            pref[v] = last[v] + 1;
        } else {
            pref[v] = pref[v-1];
        }
    }

    vi suff(X + 2, -1);
    suff[X + 1] = N;
    for (int v = X; v >= 1; v--) {
        if (last[v] != -1) {
            if (last[v] >= suff[v + 1]) break;
            suff[v] = first[v];
        } else {
            suff[v] = suff[v+1];
        }
    }

    auto works = [&](int l, int r) {
        return pref[l - 1] != -1 && suff[r + 1] != -1 &&
            pref[l - 1] <= suff[r + 1];
    };

    ll ans = 0;
    for (int l = 1, r = 1; l <= X; l++) {
        if (r < l) r++;
        while (r <= X && !works(l, r))
            r++;
        ans += X + 1 - r;
    }
    cout << ans << endl;

    return 0;
}