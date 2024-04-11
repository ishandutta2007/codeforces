#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[0] + a[1] <= a[n - 1]) {
            cout << "1 2 " << n << '\n';
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}