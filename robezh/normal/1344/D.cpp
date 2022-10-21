#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

ll k;
int n;
int a[N];
int b[N];

ll gcost(ll a, ll b) {
    return a + (-3 * b * b + 3 * b - 1);
}

ll calc_over(ll x) {
    ll res = 0;
    rep(i, 0, n) {
        int l = 0, r = a[i] + 1, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(gcost(a[i], mid) >= x) l = mid;
            else r = mid;
        }
        b[i] = l;
        res += l;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    ll l = -(ll)4e18, r = (ll)4e18, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(calc_over(mid) <= k) r = mid;
        else l = mid;
    }
    ll sum = calc_over(r);
    for(int i = n - 1; i >= 0; i--) {
        if(sum < k && b[i] < a[i] && gcost(a[i], b[i] + 1) == r - 1) {
            sum++;
            b[i]++;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
}