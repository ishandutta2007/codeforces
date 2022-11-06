#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double

void solve() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n * 2; i++) {
        int a;
        cin >> a;
        if (a & 1) v1.pb(i + 1); else v2.pb(i + 1);
    }
    for (int i = 0; i < n - 1; i++) {
        if (sz(v1) >= 2) {
            cout << v1.back() << " " << v1[sz(v1) - 2] << '\n';
            v1.pop_back();
            v1.pop_back();
        } else {
            cout << v2.back() << " " << v2[sz(v2) - 2] << '\n';
            v2.pop_back();
            v2.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}