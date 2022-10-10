#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> ans;

int solve(int n) {
    for(int d = 2; d*d <= n; d++) {
        if(n % d == 0)
            return n/d;
    }
    return 1;
}

int main() {
    for(int p = 4; p < (2 << 27); p*=2) {
        ans[p - 1] = solve(p - 1);
    }
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        if(ans.count(n)) {
            cout << ans[n] << endl;
            continue;
        }
        int p = 31 - __builtin_clz(n);
        cout << (2 << p) - 1 << endl;
    }
}