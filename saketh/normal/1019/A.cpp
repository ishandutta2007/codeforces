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

    int N, M;
    cin >> N >> M;

    vvi costs(M + 1);
    for (int i = 0; i < N; i++) {
        int vote, cost;
        cin >> vote >> cost;
        costs[vote].push_back(cost);
    }
    for (int p = 1; p <= M; p++)
        sort(all(costs[p]));

    ll ans = LLONG_MAX;
    for (int fv = costs[1].size(); fv <= N; fv++) {
        vi force_buy, rest;
        for (int p = 2; p <= M; p++) {
            int take = max(0, int(costs[p].size()) - fv + 1);
            for (int i = 0; i < costs[p].size(); i++)
                if (i < take)
                    force_buy.push_back(costs[p][i]);
                else
                    rest.push_back(costs[p][i]);
        }

        int take_rest = fv - costs[1].size() - force_buy.size();
        if (take_rest < 0)
            continue;

        ll total = 0;
        for (int v : force_buy) total += v;
        sort(all(rest));
        for (int i = 0; i < take_rest; i++)
            total += rest[i];
        ans = min(ans, total);
    }

    cout << ans << endl;
    return 0;
}