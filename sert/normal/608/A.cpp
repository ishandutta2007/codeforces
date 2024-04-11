#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int n, s, ans, h, t;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> s;
    ans = s;
    while (n --> 0) {
        cin >> h >> t;
        ans = max(ans, h + t);
    }
    cout << ans;


    return 0;
}