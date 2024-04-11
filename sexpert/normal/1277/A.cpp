#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int d = 1; d <= 9; d++) {
        ll x = d;
        while(x < INF) {
            v.push_back(x);
            x = 10*x + d;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int ans = 0;
        for(auto x : v)
            if(x <= n)
                ans++;
        cout << ans << '\n';
    }
}