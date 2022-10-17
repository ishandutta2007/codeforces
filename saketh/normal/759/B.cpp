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

    int N;
    cin >> N;

    vi time;
    vll cost;

    time.push_back(-1e9);
    cost.push_back(0);

    for (int t = 0; t < N; t++) {
        int when;
        cin >> when;

        ll best = cost.back() + 20;

        auto it = lower_bound(all(time), when - 90 + 1);
        best = min(best, cost[it - time.begin() - 1] + 50);

        it = lower_bound(all(time), when - 1440 + 1);
        best = min(best, cost[it - time.begin() - 1] + 120);

        cout << best - cost.back() << "\n";
        time.push_back(when);
        cost.push_back(best);
    }

    return 0;
}