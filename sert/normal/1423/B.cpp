#include <bits/stdc++.h>
using namespace std;

struct E {
    int a, b, c;
    E(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
    bool operator<(const E &e) const {
        return c < e.c;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    vector<E> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < m; i++) {
        a.insert(e[i].a);
        b.insert(e[i].b);
        if ((int)min(a.size(), b.size()) == n) {
            cout << e[i].c << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 1;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}