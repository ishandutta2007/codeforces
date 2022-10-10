#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, l = INT_MAX, r = 0;
        cin >> n;
        while(n--) {
            int x, y;
            cin >> x >> y;
            l = min(l, y);
            r = max(r, x);
        }
        if(l <= r)
            cout << r - l << '\n';
        else
            cout << "0\n";
    }
}