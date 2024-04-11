#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define len(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int cards = n / k;
    if (cards >= m) cout << m << '\n'; else {
        int q = m - cards;
        int l = -1, r = 1e9 + 7;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (mid * (k - 1) >= q) r = mid; else l = mid;
        }
        cout << cards - r << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}