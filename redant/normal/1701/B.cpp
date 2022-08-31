#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

void solve() {
    cin>>n;
    cout<<"2\n";
    vector<int> a;
    for (int c = 1; c <= n; c++) {
        if (c&1) {
            for (int d = c; d <= n; d*=2)
                a.push_back(d);
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        solve();
    }
    
    return 0;
}