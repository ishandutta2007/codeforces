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

    const int MAXV = 5e5 + 1;
    int zero = 0;
    vector<int> plus(MAXV), minus(MAXV);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        int tot = 0, low = 0;
        for (char c : str) {
            if (c == '(') tot++;
            else tot--;
            low = min(low, tot);
        }

        if (tot >= 0 && low < 0) continue;
        if (tot < 0 && low < tot) continue;

        if (tot == 0) {
            zero++;
        } else if (tot > 0) {
            plus[tot]++;
        } else {
            minus[-tot]++;
        }
    }

    int ans = zero / 2;
    for (int t = 1; t < MAXV; t++) {
        ans += min(plus[t], minus[t]);
    }
    cout << ans << endl;

    return 0;
}