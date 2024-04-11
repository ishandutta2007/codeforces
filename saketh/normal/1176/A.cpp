#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        ll v;
        cin >> v;

        int ans = 0;
        while (v % 2 == 0) { ans++; v /= 2; }
        while (v % 3 == 0) { ans += 2; v /= 3; }
        while (v % 5 == 0) { ans += 3; v /= 5; }
        cout << (v == 1 ? ans : -1) << "\n";
    }

    return 0;
}