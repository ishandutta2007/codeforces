#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = (a[n - 1] ^ a[n - 2]);

    vector<int> v = {a[n - 1], a[n - 2]};

    for (int i = n - 3; i >= 0; i--) {
        int m1 = a[i];
        int m2 = v.back();
        if (m1 < m2) swap(m1, m2);        
        vector<int> nw = {a[i], v.back()};
        v.pop_back();
        ans = max(ans, (m1 ^ m2));
        while (!v.empty() && (m1 == a[i] || m2 == a[i])) {            
            if (v.back() < m2) {
                v.pop_back();
                continue;
            }

            nw.push_back(v.back());
            m2 = v.back();
            v.pop_back();
            if (m2 > m1) swap(m1, m2);
            ans = max(ans, (m1 ^ m2));
        }

        for (int j = (int)nw.size() - 1; j >= 0; j--) v.push_back(nw[j]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}