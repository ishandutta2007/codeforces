#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    vector<pair<int, int>> x(k, {INT_MIN, -1});
    for (int i = 0; i < q; i++) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int id;
            scanf("%d", &id);
            id--;
            pair<int, int> p = {t[id], id};
            x.push_back(p);
            int j = x.size() - 1;
            while (j > 0 && x[j] > x[j - 1]) {
                swap(x[j], x[j - 1]);
                j--;
            }
            x.pop_back();
        } else {
            int id;
            scanf("%d", &id);
            id--;
            bool ok = false;
            for (auto p : x) {
                if (p.second == id) {
                    cout << "YES\n";
                    ok = true;
                    break;
                }
            }
            if (!ok) cout << "NO\n";
        }
    }
    
    return 0;
}