#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> trail(n); for (int i = 0; i < n; ++i) scanf("%d", &trail[i]);
    vector<int> clist{0};
    for (int v : trail) {
        if (v == clist.back() + 1) {
            ++clist.back();
        } else if (v == 1) {
            clist.push_back(1);
        } else {
            while (v != clist.back() + 1) clist.pop_back();
            ++clist.back();
        }
        printf("%d", clist[0]);
        for (int i = 1; i < clist.size(); ++i) printf(".%d", clist[i]);
        printf("\n");
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}