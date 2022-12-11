#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x; scanf("%d %d %d", &n, &m, &x);
    vector<int> h(n); for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    vector<int> si(n), ans(n, -1);
    iota(begin(si), end(si), 0);
    sort(begin(si), end(si), [&] (int i, int j) {return h[i] < h[j];});
    for (int i = 0; i < n; ++i) ans[si[i]] = i % m;
    printf("YES\n");
    for (int v : ans) printf("%d ", v + 1);
    printf("\n");
    /*
     *1
10 2 20
2 17 14 17 8 2 8 20 20 15
*/
    vector<int> checker(m);
    for (int i = 0; i < n; ++i) checker[ans[i]] += h[i];
    sort(begin(checker), end(checker));
    assert(checker.back() - checker.front() <= x);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}