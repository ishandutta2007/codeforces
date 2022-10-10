#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if(n % 2) {
        for(int i = 0; 2*i < n; i++) {
            if((s[2*i] - '0') % 2 == 1) {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    }
    else {
        for(int i = 0; 2*i + 1 < n; i++) {
            if((s[2*i + 1] - '0') % 2 == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}