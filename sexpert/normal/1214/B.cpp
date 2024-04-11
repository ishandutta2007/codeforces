#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int b, g, n, ans = 0;
    cin >> b >> g >> n;

    for(int i = 0; i <= n; i++) {
        if(i <= b && n - i <= g)
            ans++;
    }
    cout << ans << '\n';
}