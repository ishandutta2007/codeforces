#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> cnta(2000), cntb(2000);
    for(auto &x : a) {
        cin >> x;
        cnta[x]++;
    }
    for(auto &x : b) {
        cin >> x;
        cntb[x]++;
    }
    for(int i = 1; i <= 1000; i++) {
        if(cnta[i] && cntb[i]) {
            cout << "YES\n1 " << i << '\n';
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}