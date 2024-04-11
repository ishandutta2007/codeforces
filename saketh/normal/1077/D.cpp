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

    const int MAXV = 2e5 + 1;

    int N, K;
    cin >> N >> K;

    vi ct(MAXV);
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        ct[val]++;
    }

    int ans = 1, lo = 2, hi = N;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        int elts = 0;
        for (int i = 1; i < MAXV; i++) {
            elts += ct[i] / mi;
        }
        if (elts >= K) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    vi res;
    for (int i = 1; i < MAXV; i++) {
        for (int j = 0; j < ct[i] / ans; j++)
            res.push_back(i);
    }

    assert(res.size() >= K);
    for (int i = 0; i < K; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}