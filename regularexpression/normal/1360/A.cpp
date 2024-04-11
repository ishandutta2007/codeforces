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
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans1 = max(a * 2, b) * max(a * 2, b);
        int ans2 = max(b * 2, a) * max(b * 2, a);
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}