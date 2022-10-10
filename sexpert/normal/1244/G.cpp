#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll mx = 0;
    for(ll i = 1; i <= n; i++)
        mx += max(i, n + 1 - i);
    if(k < n*(n + 1)/2) {
        cout << "-1\n";
        return 0;
    }
    k = min(k, mx);
    cout << k << '\n';
    k -= n*(n + 1)/2;
    vector<int> perm;
    for(int i = 1; i <= n; i++) {
        if(k == 0) {
            for(int j = 1; j <= n + 1 - i; j++)
                perm.push_back(j);
            break;
        }
        if(k >= n + 1 - 2*i) {
            perm.push_back(n + 1 - i);
            k -= (n + 1 - 2*i);
            continue;
        }
        else {
            ll off = (n + 1 - 2*i) - k;
            int ctr = 1;
            for(int j = 0; j < n + 1 - i; j++) {
                if(j == off) {
                    perm.push_back(n + 1 - i);
                    continue;
                }
                perm.push_back(ctr);
                ctr++;
            }
            break;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << i << " ";
    cout << '\n';
    for(auto x : perm)
        cout << x << " ";
    cout << '\n';
}