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
    vector<pair<ll, int>> a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    
    int ans;
    cout << "First" << endl;
    cout << a[2].first * 10 << endl;
    cin >> ans;
    if (ans == 0) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        if (a[i].second == ans) {
            a[i].first += a[2].first * 10;
        }
    }
    sort(a.begin(), a.end());
    
    cout << a[2].first * 2 - a[1].first - a[0].first << endl;
    cin >> ans;
    if (ans == 0) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        if (a[i].second == ans) {
            a[i].first += a[2].first * 2 - a[1].first - a[0].first;
        }
    }
    sort(a.begin(), a.end());
    
    cout << a[1].first - a[0].first << endl;
    cin >> ans;
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