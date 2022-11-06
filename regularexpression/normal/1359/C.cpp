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

const int INF = 1e12;

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    if (h == t) cout << "1\n"; else {
        if (h + c >= t * 2) cout << "2\n"; else {
            int l = 0, r = INF;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((mid + 1) * h + mid * c >= t * (2 * mid + 1)) l = mid; else r = mid;
            }
            int a1 = (l + 1) * h + l * c - (2 * l + 1) * t, b1 = 2 * l + 1;
            int a2 = (2 * r + 1) * t - (r + 1) * h - r * c, b2 = 2 * r + 1;
            cout << (a1 * b2 <= b1 * a2 ? 2 * l + 1 : 2 * r + 1) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}