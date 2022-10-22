#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<char> c;
    for (int i = 0; i < k; ++i) {
        c.push_back('a' + i);
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += c[i % k];
    }
    cout << ans << "\n";
    
    return 0;
}