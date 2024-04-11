#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int pos;
    for(int i = 0; i < n; i++)
        if(v[i] == n) pos = i;
    for(int i = pos + 1; i < n - 1; i++) {
        if(v[i] < v[i + 1]) {
            cout << "No\n";
            return 0;
        }
    }
    for(int i = pos - 1; i >= 1; i--) {
        if(v[i] < v[i - 1]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}