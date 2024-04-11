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

    int N, K;
    cin >> N >> K;

    if (K == 1) {
        cout << '1';
        for (int i = 1; i < N; i++)
            cout << '0';
        cout << endl;
        return 0;
    }

    int X = (N - K + 2)/2;

    stringstream res;
    for (int i = 0; i < N; i++) {
        if (i % X == 0) res << '1';
        else res << '0';
    }

    string ans = res.str();

    /*for (int len = 1; len < K; len++) {
        map<string, int> ct;
        for (int i = 0; i + len <= N; i++) {
            ct[ans.substr(i, len)]++;
        }
        for (auto [str, app] : ct)
            assert(app != 1);
    }

    string uniq = ans.substr(X - 1, K);
    for (int i = 0; i + K <= N; i++) {
        if (i != X - 1)
        assert(ans.substr(i, K) != uniq);
    }*/

    cout << ans << endl;

    return 0;
}