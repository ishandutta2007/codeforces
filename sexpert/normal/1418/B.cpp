#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), lock, ulock;
    for(auto &x : a)
        cin >> x;
    for(auto &x : l)
        cin >> x;
    for(int i = 0; i < n; i++)
        (l[i] ? lock : ulock).push_back(a[i]);
    sort(ulock.rbegin(), ulock.rend());
    int p1 = 0, p2 = 0;
    for(int i = 0; i < n; i++) {
        if(l[i])
            cout << lock[p1++] << " ";
        else
            cout << ulock[p2++] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}