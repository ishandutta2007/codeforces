#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] = a[i] * a[i] % 3;
    }
    vector<int> c(3, 0);
    for (auto x: a) c[x] ++;

    int idx = 0, mx = 0;
    for (int i = 0; i < 3; i ++) {
        if (c[i] >= mx) {
            mx = c[i], idx = i;
        }
    }
    vector<bool> vis(n, 0);
    if (mx < n / 2) {
        cout << -1 << "\n"; 
        return 0;
    }
    
    int used = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == idx and used < n / 2) {
            used ++;
            vis[i] = 1;
        }    
    }
    set<int> st = {0, 1, 2};
    for (int i = 0; i < n; i ++) if (not vis[i]) {
        int tmp = (idx + a[i]) % 3;
        if (st.count(tmp)) st.erase(tmp);
    }
    if (st.empty()) {
        cout << -1 << "\n"; return 0;
    }
    cout << *st.begin() << "\n";
    for (auto x: vis) cout << (x?1:0);
    cout << "\n";
    //for (auto x: a) cout << x << "\n";
}