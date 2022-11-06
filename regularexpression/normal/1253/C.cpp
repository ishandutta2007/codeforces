#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

typedef long long ll;
typedef long double ld;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[n - i - 1] * (i / m + 1);
    }
    vector<int> s(m, 0);
    for (int i = 0; i < n; i++) {
        s[i % m] += a[i];
    }
    vector<int> ans(n);
    for (int i = n - 1; i > -1; i--) {
        ans[i] = cur;
        cur -= s[i % m];
        s[i % m] -= a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}