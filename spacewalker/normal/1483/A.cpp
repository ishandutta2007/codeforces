#include <bits/stdc++.h>

using namespace std;

int ceil(int n, int d) {return n / d + (n % d == 0 ? 0 : 1);}

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<int, int>> pwede(m);
    for (int i = 0; i < m; ++i) {
        int k; scanf("%d", &k);
        vector<int> ppl(k);
        for (int j = 0; j < k; ++j) scanf("%d", &ppl[j]);
        if (k == 1) {
            pwede[i] = {ppl[0], -1};
        } else {
            pwede[i] = {ppl[0], ppl[1]};
        }
    }
    vector<int> ans(m, -1), occs(n + 1);
    for (int i = 0; i < m; ++i) {
        if (pwede[i].second == -1) {
            ans[i] = pwede[i].first;
            ++occs[ans[i]];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i] != -1) continue;
        int ctp = (occs[pwede[i].first] > occs[pwede[i].second] ? pwede[i].second : pwede[i].first); 
        ans[i] = ctp;
        ++occs[ctp];
    }
    for (int v : occs) {
        if (v > ceil(m,2)) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for (int v : ans) printf("%d ", v);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}