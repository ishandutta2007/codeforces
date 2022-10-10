#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, int, greater<int>> cta, ctb;
    set<int, greater<int>> keys;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cta[x]++;
        keys.insert(x);
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ctb[x]++;
        keys.insert(x);
    }
    int sa = 0, sb = 0;
    for(auto k : keys) {
        sa += cta[k];
        sb += ctb[k];
        if(sa > sb) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}