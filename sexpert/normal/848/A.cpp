#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    cin >> k;
    if(k == 0) {
        cout << "a\n";
        return 0;
    }
    vector<ll> cst;
    for(ll x = 0; x <= 2000; x++)
        cst.push_back({x * (x + 1) / 2LL});
    string ans;
    char cur = 'a';
    //for(int i = 0; i <= 10; i++)
    //    cout << cst[i] << " ";
    //cout << '\n';
    for(int i = 1000; i >= 1; i--) {
        while(k >= cst[i]) {
            k -= cst[i];
            for(int j = 0; j <= i; j++)
                ans += cur;
            cur++;
        }
    }
    cout << ans << '\n';
}