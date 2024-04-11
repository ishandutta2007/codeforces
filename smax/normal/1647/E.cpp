#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> p(n), deg(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
        deg[--p[i]]++;
    }
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    int inc = 0;
    for (int x : deg)
        inc += max(x - 1, 0);
    int steps = (*max_element(a.begin(), a.end()) - n) / inc;
    
    vector<vector<int>> up(LOG, vector<int>(n));
    up[0] = p;
    for (int i=1; i<LOG; i++)
        for (int j=0; j<n; j++)
            up[i][j] = up[i-1][up[i-1][j]];
    
    vector<int> b(n), targ(n), inv(n, -1);
    set<int> st;
    for (int i=1; i<=n; i++)
        st.insert(i);
    for (int i=0; i<n; i++) {
        int u = i;
        for (int j=0; j<LOG; j++)
            if (steps >> j & 1)
                u = up[j][u];
        targ[i] = u;
        if (inv[u] == -1 && a[u] <= n) {
            b[i] = a[u];
            inv[u] = i;
            st.erase(a[u]);
        }
    }
    
    for (int i=0; i<n; i++) {
        if (b[i] == 0) {
            auto it = st.upper_bound(b[inv[targ[i]]]);
            b[i] = *it;
            st.erase(it);
        }
        cout << b[i] << " ";
    }
    cout << "\n";
    
    return 0;
}