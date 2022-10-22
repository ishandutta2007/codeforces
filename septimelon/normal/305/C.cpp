#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    set<int> ones;
    int curm = 0;
    for (int i = n - 1; i >= 0; --i) {
        int cur = a[i];
        while (ones.count(cur) > 0) {
            ones.erase(cur);
            ++cur;
        }
        ones.insert(cur);
        curm = max(cur, curm);
    }
    
    cout << curm + 1 - ones.size() << "\n";
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