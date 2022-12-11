#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
const int INF = (int)1e9 + 41;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> es(n);
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x--;
    }
    bool ok = true;
    
    queue<int> q;
    q.push(0);

    vector<int> pr(n, -1);    
    for (int i = 0; ok && i < n; i++, q.pop()) {
        int v = a[i];
        if (v != q.front()) {
            ok = false;
            continue;
        }
        vector<int> c1;
        for (int w : es[v]) if (w != pr[v]) c1.push_back(w);
        if (i + (int)c1.size() + (int)q.size() > n) {
            ok = false;
            continue;
        }
        vector<int> c2;
        int sz = i + q.size();
        for (int j = 0; j < (int)c1.size(); j++) {
            pr[a[j + sz]] = v;
            c2.push_back(a[j + sz]);            
            q.push(a[j + sz]);
        }
        
        sort(all(c1));
        sort(all(c2));
        ok &= (c1 == c2);        
    }


    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}