#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> dep;
    dep[a[0]] = 0;
    set<int> good = {a[0]};
    for (int i = 1; i < n; i++) {
        int prv = good.upper_bound(a[i]) == good.end() ? -1 : *good.upper_bound(a[i]);
        int nxt = good.upper_bound(a[i]) == good.begin() ? -1 : *prev(good.upper_bound(a[i]));
        if (prv == -1 || (nxt != -1 && dep[nxt] > dep[prv])) {
            cout << nxt << " ";
            good.insert(a[i]);
            dep[a[i]] = dep[nxt] + 1;
        } else {
            cout << prv << " ";
            good.insert(a[i]);
            dep[a[i]] = dep[prv] + 1;
        }
    }
    return 0;
}