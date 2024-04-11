#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            r.push_back(i + 1);
            r.push_back(1);
            r.push_back(i + 1);
        }
    }
    
    cout << r.size();
    for (int i = 0; i < r.size(); ++i) {
        cout << " " << r[i];
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