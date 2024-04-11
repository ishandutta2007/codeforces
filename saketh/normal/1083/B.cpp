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

    string s, t;
    cin >> s >> t;

    ll ans = 0;

    bool diverge = s[0] != t[0];
    ll btw = 0;

    for (int i = 0; i < N; i++) {
        if (btw + 1 + diverge < K) {
            ans += btw + 1 + diverge;
            if (i + 1 < N) {
                btw *= 2;
                if (!diverge) {
                    diverge |= (s[i+1] != t[i+1]);
                } else {
                    if (s[i+1] == 'a') btw++;
                    if (t[i+1] == 'b') btw++;
                }
            }
        } else {
            ans += K;
        }
    }

    cout << ans << endl;
    return 0;
}