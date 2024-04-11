#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        LL n;
        cin >> n;
        LL ans = n + n / 2 * 2 + n / 3 * 2;
        cout << ans << '\n';
    }
}