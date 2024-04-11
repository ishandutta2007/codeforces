#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> s;

    for(int k = 1; k * k <= n; k++) {
        s.insert(n / k);
    }

    for(int i = 0; i * i <= n; i++) {
        int l = 0, r = n + 2;
        while(r - l > 1) {
            int m = (l + r) / 2;

            if(n / m > i)
                l = m;
            else
                r = m;
        }

        s.insert(n / r);
    }

    cout << s.size() << endl;
    for(auto s1 : s)
        cout << s1 << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}