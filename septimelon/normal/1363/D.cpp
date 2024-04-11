#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;
const ll LINF = 1000000000000000009LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k);
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
        sort(a[i].begin(), a[i].end());
    }
    
    int tmax;
    cout << "? " << n;
    for (int i = 1; i <= n; ++i) {
        cout << " " << i;
    }
    cout << endl;
    cin >> tmax;
    
    int l = 0, r = k;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        vector<int> q;
        for (int i = l; i < mid; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                q.push_back(a[i][j]);
            }
        }
        cout << "? " << q.size();
        for (int i = 0; i < q.size(); ++i) {
            cout << " " << q[i];
        }
        cout << endl;
        q.clear();
        int cm;
        cin >> cm;
        if (cm == tmax) {
            r = mid;
        } else {
            l = mid;
        }
    }
    a[l].push_back(INF);
    
    int ia = 0;
    cout << "? " << n - a[l].size() + 1;
    for (int i = 1; i <= n; ++i) {
        if (a[l][ia] == i) {
            ++ia;
            continue;
        }
        cout << " " << i;
    }
    cout << endl;
    int nm;
    cin >> nm;
    
    cout << "!";
    for (int i = 0; i < l; ++i) {
        cout << " " << tmax;
    }
    cout << " " << nm;
    for (int i = l + 1; i < k; ++i) {
        cout << " " << tmax;
    }
    cout << endl;
    
    string ans;
    cin >> ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}