#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

vll fact = { 1 };
ll factorial(int f) {
    while (fact.size() <= f)
        fact.push_back(fact.back() * fact.size());
    return fact[f];
}

ll permute(int sum, vi &used, bool lead_zero) {
    ll res = factorial(sum);
    for (int v : used) res /= factorial(v);
    if (!lead_zero) {
        res *= sum - used[0];
        res /= sum;
    }
    return res;
}

ll dfs(vi &can, vi &fit, vi &used, int sum, int need, int lvl, bool lead_zero) {
    if (need < 0 || fit[lvl] < need) return 0;
    if (lvl == 15) {
        used[15] = need;
        return permute(sum, used, lead_zero);
    }

    ll res = 0;
    for (used[lvl] = 0; used[lvl] <= can[lvl]; used[lvl]++) {
        res += dfs(can, fit, used, sum, need - used[lvl], lvl + 1, lead_zero);
    }
    return res;
}

ll ways(vi left, int digs, bool lead_zero) {
    WATCHC(left);
    WATCH(digs);

    vi fit = left;
    for (int d = 14; d >= 0; d--)
        fit[d] += fit[d+1];

    vi used(16, 0);
    ll ret = dfs(left, fit, used, digs, digs, 0, lead_zero);
    WATCH(ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int K, T;
    cin >> K >> T;

    int D = 1;
    vi left(16, T);

    while (true) {
        ll dw = ways(left, D, false);
        if (dw < K) {
            K -= dw;
            D++;
        } else break;
    }

    vi ans(D);
    for (int i = 0; i < D; i++) {
        for (ans[i] = (i ? 0 : 1); ans[i] < 16; ans[i]++) {
            left[ans[i]]--;
            ll rest = ways(left, D - i - 1, true);
            if (rest < K) {
                K -= rest;
                left[ans[i]]++;
            } else break;
        }
    }

    string digs = "0123456789abcdef";
    for (int v : ans) {
        cout << digs[v];
    }
    cout << endl;

    return 0;
}