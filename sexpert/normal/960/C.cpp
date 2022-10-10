#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> sz(1);
    for(int i = 1; i <= 30; i++)
        sz.push_back((1 << i) - 1);
    vector<ll> ans;
    ll X, d, cur = 1;
    cin >> X >> d;
    while(X) {
        int l = 30;
        for(; l >= 1; l--)
            if(sz[l] <= X)
                break;
        for(int i = 0; i < l; i++)
            ans.push_back(cur);
        X -= sz[l];
        cur += d + 1;
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}