#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        int n, a,b,c,d;
        cin >> n >> a >> b >> c >> d;

        int l = (a-b)*n;
        int r = (a+b)*n;

        int lc = c-d;
        int rc = c+d;

        if ( (l <= lc && lc <= r) || (l <= rc && rc <= r) || (lc <= l && l <= rc) || (lc <= r && r <= rc)) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }

    return 0;
}