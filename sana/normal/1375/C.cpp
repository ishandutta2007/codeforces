#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t,n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (cin >> t; t; t--) {
        cin >> n; vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (a[0] < a[n-1] ? "YES" : "NO") << '\n';
    }
    
    return 0;
}