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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int pos = 0;
    while (pos < n) {
        int id = -1;
        for (int i = pos; i < n; i++) {
            if (a[i] <= i + 1) {
                id = i;
                break;
            }
        }
        if (id == -1) break;
        pos = id + 1;
    }
    cout << pos + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}