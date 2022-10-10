#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    
    for(auto &x : v)
        cin >> x;

    while(v.size() && v.back() == v.size())
        v.pop_back();

    double bad = 1.0;
    for(int i = 0; i < m; i++) {
        int s;
        double p;
        cin >> s >> p;
        if(s >= v.size())
            bad *= (1.0 - p);
    }

    if(v.size() == 0) {
        cout << "1.000000\n";
        return;
    }

    cout << fixed << setprecision(6) << (1.0 - bad) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}