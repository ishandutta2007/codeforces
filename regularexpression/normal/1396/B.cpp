#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mx = max(mx, a);
            sum += a;
        }
        if (mx > sum - mx)
            cout << "T\n";
        else
            cout << ((sum & 1) ? "T\n" : "HL\n");
    }
    return 0;
}