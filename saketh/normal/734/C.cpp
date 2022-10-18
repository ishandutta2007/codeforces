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

int find_rate(vector<pair<int, int>> &rates, int mana) {
    auto it = upper_bound(all(rates), make_pair(mana, INT_MAX));
    return prev(it)->second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, A, B;
    cin >> N >> A >> B;

    int X, S;
    cin >> X >> S;

    vector<pair<int, int>> rates;
    rates.emplace_back(0, X);

    vector<pair<int, int>> spells(A);
    for (int i = 0; i < A; i++)
        cin >> spells[i].second;
    for (int i = 0; i < A; i++)
        cin >> spells[i].first;
    sort(all(spells));

    for (auto p : spells) {
        if (p.second >= rates.back().second) continue;
        if (p.first == rates.back().first) rates.pop_back();
        rates.push_back(p);
    }

    ll ans = N * 1ll * find_rate(rates, S);

    vector<int> pot(B), cost(B);
    for (int i = 0; i < B; i++)
        cin >> pot[i];
    for (int i = 0; i < B; i++)
        cin >> cost[i];

    for (int i = 0; i < B; i++) {
        if (cost[i] > S) continue;
        ans = min(ans, max(0, N - pot[i]) * 1ll * find_rate(rates, S - cost[i]));
    }

    cout << ans << "\n";
    return 0;
}