#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

const int PRE_COMP = 1e6;

//unordered_map<ll, pair<int, ll>> cache;
vector<ll> cubes(PRE_COMP);

pair<int, ll> solve(vector<pair<int, ll>> &best, ll val) {
    if (val < PRE_COMP) {
        return best[val];
    }
    //if (cache.count(val)) return cache[val];

    auto it = upper_bound(cubes.begin(), cubes.end(), val);
    pair<int, ll> ans = { 0, 0 };

    for (int i = 0; i < 2; i++) {
        ll limit = min(val, *it - 1);
        it--;
        limit -= *it;

        auto rec = solve(best, limit);
        ans = max(ans, { rec.first + 1, *it + rec.second });
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (ll i = 0; i < PRE_COMP; i++)
        cubes[i] = i * i * i;

    vector<int> steps(PRE_COMP);
    vector<pair<int, ll>> best(PRE_COMP);

    steps[0] = 0;
    best[0] = { 0, 0 };

    int croot = 0;

    for (int v = 1; v < PRE_COMP; v++) {
        while (cubes[croot+1] <= v) croot++;
        steps[v] = steps[v - cubes[croot]] + 1;
        best[v] = max(best[v-1], { steps[v], v });
    }

    ll inp;
    cin >> inp;
    auto res = solve(best, inp);
    cout << res.first << " " << res.second << "\n";

    return 0;
}
;