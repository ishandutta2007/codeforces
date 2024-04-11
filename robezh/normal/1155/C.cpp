#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n, m;
ll x[N], p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < m; i++) cin >> p[i];
    ll g = 0;
    for(int i = 0; i < n - 1; i++) g = __gcd(g, x[i+1] - x[i]);
    for(int i = 0; i < m; i++) {
        if(g % p[i] == 0) {
            cout << "YES" << endl;
            cout << x[0] << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;


}