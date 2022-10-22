/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

set<pll> st;
set<ll> lst[MAXN], rst[MAXN], ust[MAXN], dst[MAXN];
ll n, m, k;

int main() {
    cin >> n >> m >> k;
    ll u = 0, d = n + 1, l = 0, r = m + 1;

    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        st.insert({x, y});
        dst[y].insert(x);
        ust[y].insert(-x);
        rst[x].insert(y);
        lst[x].insert(-y);
    }

    ll dir = 0, cnt = 0;
    while (u + 1 < d && l + 1 < r) {
        if (dir == 0) {
            u++;
            auto it = rst[u].lower_bound(l + 1);
            if (it != rst[u].end()) r = min(*it, r);
            cnt += r - l - 1;
        } else if (dir == 1) {
            r--;
            auto it = dst[r].lower_bound(u + 1);
            if (it != dst[r].end()) d = min(*it, d);
            cnt += d - u - 1;
        } else if (dir == 2) {
            d--;
            auto it = lst[d].lower_bound(-1 * (r - 1));
            if (it != lst[d].end()) l = max(-1 * (*it), l);
            cnt += r - l - 1;
        } else if (dir == 3) {
            l++;
            auto it = ust[l].lower_bound(-1 * (d - 1));
            if (it != ust[l].end()) u = max(-1 * (*it), u);
            cnt += d - u - 1;
        }

        dir++;
        dir %= 4;
    }

    if (cnt == n * m - k) return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    return 0;
}