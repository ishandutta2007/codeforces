#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1000000000000000000;

vector<int> par;
vector<vector<int>> child;
vector<ll> sumvalues;
vector<ll> values;

bool attemptFillValues(int v) {
    if (sumvalues[v] == -1 && !child[v].empty()) {
        // attempt to fill this node, and its children
        ll leastValue = INF;
        ll weightFromAbove = sumvalues[par[v]];
        for (int c : child[v]) leastValue = min(leastValue, sumvalues[c]);
        if (leastValue < weightFromAbove) return false;
        values[v] = leastValue - weightFromAbove;
        for (int c : child[v])
        values[c] = sumvalues[c] - (weightFromAbove + values[v]);
    }
    for (int c : child[v]) {
        if (!attemptFillValues(c)) return false;
    }
    return true;
}

int main() {
    int n; scanf("%d", &n);
    par = vector<int>(n, -1);
    child = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
        int x; scanf("%d", &x); --x;
        par[i] = x;
        child[par[i]].push_back(i);
    }
    values = sumvalues = vector<ll>(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &sumvalues[i]);
    values[0] = sumvalues[0];
    if (attemptFillValues(0)) {
        ll total = 0;
        for (int x : values) total += x;
        printf("%lld\n", total);
    } else {
        printf("-1\n");
    }
    
    return 0;
}