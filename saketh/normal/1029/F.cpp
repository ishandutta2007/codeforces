#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vector<array<ll, 2>> rect(ll N) {
    vector<array<ll, 2>> res;
    for (ll s1 = 1; s1 * s1 <= N; s1++) {
        if (N % s1 == 0)
            res.push_back({ s1, N/s1 });
    }
    return res;
}

ll check(ll N, ll M) {
    auto outer = rect(N);
    auto inner = rect(M);

    ll ans = LLONG_MAX;
    for (auto o : outer) {
        array<ll, 2> s = { o[0], LLONG_MAX };
        auto it = upper_bound(all(inner), s);
        if (it != inner.begin() && (*prev(it))[1] <= o[1]) {
            ans = min(ans, 2 * (o[0] + o[1]));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll A, B;
    cin >> A >> B;
    cout << min(check(A+B, A), check(A+B, B)) << endl;

    return 0;
}