#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask1(int u, int v) {
    cout << "1 " << u << " " << v << endl;
    int r;
    cin >> r;
    return r;
}

int ask2(int u, vector<int> &v) {
    cout << "2 " << u << " " << v.size() << " ";
    for(auto &x : v)
        cout << x << " ";
    cout << endl;
    int r;
    cin >> r;
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> path = {0};
    vector<vector<int>> ans(n, vector<int>(n));
    for(int k = 1; k < n; k++) {
        int sz = path.size();
        if(ask1(k, path[0])) {
            path.insert(path.begin(), k);
            continue;
        }
        if(ask1(path[sz - 1], k)) {
            path.push_back(k);
            continue;
        }
        int lo = 0, hi = sz - 1;
        while(hi - lo > 1) {
            int mi = (lo + hi)/2;
            if(ask1(k, path[mi]))
                hi = mi;
            else
                lo = mi;
        }
        path.insert(path.begin() + hi, k);
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            ans[path[i]][path[j]] = 1;

    vector<int> scc;
    for(int r = n - 1, l = n - 1; r >= 0; r--) {
        scc.push_back(path[r]);
        vector<int> guys(path.begin(), path.begin() + l);
        while(l && ask2(path[r], guys)) {
            l--;
            guys.pop_back();
        }
        if(l == r) {
            for(auto &x : scc)
                for(auto &y : scc)
                    ans[x][y] = 1;
            scc.clear();
            l--;
        }
    }

    cout << "3\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << '\n';
    }
    cout.flush();
    int x;
    cin >> x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}