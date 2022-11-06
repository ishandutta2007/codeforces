#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

const int M = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    vector<int> p(n + 1, 1);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] * 2 % M;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = n - i - 1;
        if (c != 0) {
            ans += c * p[c - 1] % M * a[i] % M;
            ans %= M;
        }
        ans += p[c] * a[i] % M;
        ans %= M;
    }
    cout << ans;
    return 0;
}