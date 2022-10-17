#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, S;
    cin >> N >> S;

    vi s(N), a(N), b(N);

    ll tot = 0;
    ll happy = 0;
    vector<pair<ll, ll>> gain;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> a[i] >> b[i];

        tot += s[i];
        happy += s[i] * 1ll * a[i];
        gain.emplace_back(b[i] - a[i], s[i]);
    }

    ll buy = (tot + S - 1) / S;
    gain.emplace_back(0, buy * S - tot);

    sort(all(gain));
    reverse(all(gain));

    ll ans = happy;

    ll run = 0;
    ll val = 0;

    for (auto &p : gain) {
        if (run) {
            // If we still can't make a whole pizza to switch over, combine and move on
            if (run + p.second < S) {
                run += p.second;
                val += p.first * p.second;
                continue;
            }

            // Else complete the current pizza and switch it over to type B
            val += (S - run) * p.first;
            p.second -= S - run;

            happy += val;
            ans = max(ans, happy);

            run = 0;
            val = 0;
        }

        // If no partial pizza, and all values left are non-positive, just stop
        if (p.first <= 0) break;

        // Gain is positive, take all the whole pizzas we can make
        happy += (p.second / S) * S * p.first;
        ans = max(ans, happy);

        run = p.second % S;
        val = run * p.first;
    }

    cout << ans << endl;
    return 0;
}