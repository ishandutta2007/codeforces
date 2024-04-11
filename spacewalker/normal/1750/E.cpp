#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick {
    int n;
    vector<ll> tree;
    int LSB(int i) {
        return (i & (-i));
    }
    fenwick() {}
    fenwick(int n) : n(n), tree(n+1) {}
    void add(int i, ll v) {
        for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;
    }
    ll getPrefix(int i) {
        ll ans = 0;
        for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
        return ans;
    }
    ll getRange(int i, int j) {
        return getPrefix(j) - getPrefix(i-1);
    }
};

ll asumTotal(const vector<ll> &diffs) {
    // for all pairs of i < j such that P[i] < P[j],
    // get sum of P[j] - P[i]
    // sum over j
    int n = diffs.size();
    vector<pair<ll, int>> elems;
    for (int i = 0; i < n; ++i) elems.emplace_back(diffs[i], i);
    sort(begin(elems), end(elems));
    fenwick ct(n), value(n);
    ll ans = 0;
    for (auto [cval, cidx] : elems) {
       ans += ct.getRange(0, cidx) * cval - value.getRange(0, cidx); 
       ct.add(cidx, 1);
       value.add(cidx, cval);
    }
    return ans;
}

ll vminTotal(const vector<ll> &diffs) {
    int n = diffs.size();
    vector<pair<ll, int>> partialMins{{diffs[n-1], 1}};
    ll stackSum = diffs[n-1];
    auto addElement = [&] (ll v) {
        ll removedLen = 0, removedSum = 0;
        while (!partialMins.empty() && partialMins.back().first >= v) {
            auto [topv, topc] = partialMins.back();
            removedLen += topc;
            removedSum += topc * topv;
            partialMins.pop_back();
        }
        stackSum -= removedSum;
        partialMins.emplace_back(v, removedLen + 1);
        stackSum += v * (removedLen + 1);
    };
    ll ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        addElement(diffs[i]);
        ans += (n - i) * diffs[i] - stackSum;
    }
    return ans;
}

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> diffs(n + 1);
    for (int i = 0; i < n; ++i) diffs[i+1] = (s[i] == '(' ? 1 : -1) + diffs[i];

    return vminTotal(diffs) + asumTotal(diffs);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}