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

    int N;
    cin >> N;

    string trop;
    cin >> trop;

    int ans = 0, totG = 0;

    vi pref(N);
    for (int i = 0; i < N; i++) {
        if (trop[i] == 'G') {
            pref[i] = 1 + (i ? pref[i-1] : 0);

            ans = max(ans, pref[i]);
            totG++;
        }
    }

    vi suff(N);
    for (int i = N - 1; i >= 0; i--) {
        if (trop[i] == 'G') {
            suff[i] = 1 + (i+1 < N ? suff[i+1] : 0);
        }
    }

    for (int i = 0; i < N; i++) {
        if (trop[i] == 'S') {
            int cand = 1 + (i ? pref[i-1] : 0) + (i+1 < N ? suff[i+1] : 0);
            cand = min(cand, totG);
            ans = max(ans, cand);
        }
    }

    cout << ans << endl;
    return 0;
}