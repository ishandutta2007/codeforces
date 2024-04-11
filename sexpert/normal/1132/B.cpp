#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
        cin >> v[i], sum += v[i];
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    while(m--) {
        int q;
        cin >> q;
        cout << sum - v[n - q] << '\n';
    }
}