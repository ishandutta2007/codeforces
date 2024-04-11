#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int query(int i) {
    cout << "? " << i << endl;
    int qi;
    cin >> qi;
    return qi;
}
int main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i += 1) if (not p[i]) {
            while (query(i) != i);
            vector<int> v;
            while (true) {
                int x = query(i);
                v.push_back(x);
                if (x == i) break;
            }
            for (int i = 0; i < v.size(); i += 1) p[v[i]] = v[(i + 1) % v.size()];
        }
        cout << "!";
        for (int i = 1; i <= n; i += 1) cout << " " << p[i];
        cout << endl;
    }
    return 0;
}