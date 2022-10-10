#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> dp[2];
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int g = 0;
    int odd = 0;
    for(auto &x : v) {
        cin >> x;
        if(g == 0)
            g = x;
        else
            g = __gcd(g, x);
        if(x % 2)
            odd++;
    }
    if(g > 1) {
        cout << "YES\n0\n";
        return 0;
    }
    for(auto &x : v)
        x %= 2;
    int ans = 0;
    int cnt = 0;
    for(auto &x : v) {
        if(x == 1)
            cnt++;
        else {
            ans += cnt/2 + 2*(cnt % 2);
            cnt = 0;
        }
    }
    ans += cnt/2 + 2*(cnt % 2);

    cout << "YES\n";
    cout << ans << '\n';
}