#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    string s, p;
    cin >> s >> p;
    int n, m;
    n = s.size();
    m = p.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }
    
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int cj = 0;
        for (int i = 0; i < n; ++i) {
            if (p[cj] == s[i] && b[i] >= mid) {
                ++cj;
                if (cj == m) {
                    break;
                }
            }
        }
        if (cj == m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}