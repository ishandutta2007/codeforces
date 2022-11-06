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

const int INF = 2e18;

int solve(vi a) {
    int mn = 0, sum = 0, res = -INF;
    for (auto val : a) {
        sum += val;
        res = max(res, sum - mn);
        mn = min(mn, sum);
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -INF;
    for (int val = -50; val <= 50; val++) {
        vi cur;
        for (int i = 0; i < n; i++) {
            if (a[i] > val) {
                ans = max(ans, solve(cur) - val);
                cur.clear();
            } else cur.pb(a[i]);
        }
        ans = max(ans, solve(cur) - val);
    }
    cout << ans;
    return 0;
}