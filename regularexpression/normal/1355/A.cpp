#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define ll long long
#define ld long double
#define int long long

int f(int a) {
    int mn = 1e9, mx = -1e9;
    int aa = a;
    while (a > 0) {
        mn = min(mn, a % 10);
        mx = max(mx, a % 10);
        a /= 10;
    }
    return aa + mn * mx;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, k;
        cin >> a >> k;
        vector<int> v = {a};
        while (f(v.back()) != v.back()) v.pb(f(v.back()));
        if (k <= sz(v)) cout << v[k - 1]; else cout << v.back();
        cout << '\n';
    }
    return 0;
}