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

    int N;
    cin >> N;

    int mx = 0;

    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        mx = max(mx, val[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && val[j] == val[i])
            j++;
        if (val[i] == mx) {
            ans = max(ans, j - i);
        }
        i = j;
    }
    cout << ans << endl;

    return 0;
}