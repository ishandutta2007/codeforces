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

ll alice(int N, const vi& a) {
    ll res = 0, cur = 0, K = -1;
    for (int i = 0; i < N; i++) {
        cur += a[i];
        if (cur < 0) {
            cur = 0;
            K = i;
        }
        res = max(res, (i-K) * cur);
    }
    return res;
}

ll good(int N, const vi& a) {
    vll pref(N + 1);
    for (int i = 0; i < N; i++) {
        pref[i+1] = pref[i] + a[i];
    }

    ll res = LLONG_MIN;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            res = max(res, (r - l + 1) * (pref[r+1] - pref[l]));
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    /*vi test = { 6, -8, 7, -42 };
    cout << alice(4, test) << endl;
    cout << good(4, test) << endl;*/

    const int MAXV = 1e6;
    const int N = 1500;

    map<int, int> choices;
    for (int X = MAXV; X > MAXV - N; X--) {
        int res = (X * (N - 1)) % N;
        choices[res] = X;
    }
    assert(choices.size() == N);

    ll K;
    cin >> K;

    int X = choices[K % N];
    ll D = 1499ll * X - K;
    assert(D >= 0);
    assert(D % 1500 == 0);
    int Y = D / 1500;
    assert(abs(Y) <= MAXV);

    vi res(N, 0);
    res[N - 2] = -Y;
    res[N - 1] = X;

    ll a = alice(N, res);
    ll b = good(N, res);
    assert(b - a == K);

    cout << N << "\n";
    for (int v : res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}