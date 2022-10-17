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

    string s;
    cin >> s;

    int e = 0, i = 0, n = 0, t = 0;

    for (char c : s) {
        if (c == 'e') e = e + 1;
        if (c == 'i') i = i + 1;
        if (c == 'n') n = n + 1;
        if (c == 't') t = t + 1;
    }

    int ans = 0;
    for (int X = 0; X <= 14; X++) {
        if (X <= i && X <= t &&
                2 * X + 1 <= n && 3 * X <= e)
            ans = max(ans, X);
    }

    cout << ans << endl;
    return 0;
}