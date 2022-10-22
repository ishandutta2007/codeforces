#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 0, s = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(a == 0) {
            res++;
            a++;
        }

        s += a;
    }

    cout << res + (s == 0) << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}