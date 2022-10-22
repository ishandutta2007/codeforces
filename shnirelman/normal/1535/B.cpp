#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 1)
            b.push_back(a[i]);
    }

    int ans = n * (n - 1) / 2 - b.size() * (b.size() - 1) / 2;

    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < i; j++)
            ans += (__gcd(b[i], b[j]) > 1);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}