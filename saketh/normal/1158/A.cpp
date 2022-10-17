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

    int N, M;
    cin >> N >> M;

    ll tot = 0;

    vi boy(N);

    for (int i = 0; i < N; i++) {
        cin >> boy[i];
        tot += boy[i] * 1ll * M;
    }

    sort(all(boy));

    vi girl(M);
    for (int i = 0; i < M; i++) {
        cin >> girl[i];
        if (girl[i] < boy.back()) {
            cout << -1 << endl;
            return 0;
        }
    }

    sort(all(girl));

    for (int i = 1; i < M; i++) {
        tot += girl[i] - boy.back();
    }

    if (girl.front() > boy.back()) {
        tot += girl.front() - boy[N - 2];
    }

    cout << tot << endl;

    return 0;
}