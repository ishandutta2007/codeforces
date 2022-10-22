#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
        if(abs(a[i] - a[i - 1]) >= 2){
            cout << "YES" << endl;
            cout << i << ' ' << i + 1 << endl;
            return;
        }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}