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

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vll suff(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }

    ll ans = suff[0];

    suff.pop_back();
    suff.erase(suff.begin());
    sort(all(suff), greater<ll>());

    for (int i = 0; i < K - 1; i++)
        ans += suff[i];
    cout << ans << endl;

    return 0;
}