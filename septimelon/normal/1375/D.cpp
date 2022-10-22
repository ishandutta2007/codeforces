#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

int mex(const vector<int>& c) {
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == 0) {
            return i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> ans;
    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++count[a[i]];
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) {
            continue;
        }
        while (mex(count) < n) {
            int cm = mex(count);
            --count[a[cm]];
            ++count[cm];
            a[cm] = cm;
            ans.push_back(cm);
        }
        if (a[i] != i) {
            --count[a[i]];
            ++count[n];
            for (int j = i + 1; j < n; ++j) {
                if (a[j] == i) {
                    a[j] = n;
                    a[i] = i;
                    ans.push_back(j);
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
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