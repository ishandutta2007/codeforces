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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, At[MAXN], a[MAXN];
pll C[MAXN];
ll prv[MAXN] = {0};
ll nex[MAXN] = {0};

ll algo(ll* b) {
    stack<ll> st;
    for (ll i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) b[i] = -1;
        else b[i] = st.top();
        st.push(i);
    }

    return 0;
}

map<ll, vector<ll>> mp;

void prep() {
    for (ll i = 0; i < n; i++) C[i].X = a[i], C[i].Y = i;
    sort(C, C + n);
    vector<ll> tmp;
    ll p = INF;
    for (ll i = 0; i < n; i++) {
        if (C[i].X != p) {
            mp[p] = tmp;
            p = C[i].X;
            tmp.clear();
        }

        tmp.push_back(C[i].Y);
    }

    mp[p] = tmp;
    tmp.clear();
}

ll count_in_range(ll l, ll r, ll x) {
    return (upper_bound(all(mp[x]), r) - mp[x].begin()) - (lower_bound(all(mp[x]), l) - mp[x].begin());
}

int main() {
    fast_io;
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> At[i];
    ll ind = max_element(At, At + n) - At;
    for (ll i = ind; i < n; i++) a[i - ind] = At[i] * -1;
    for (ll i = 0; i < ind; i++) a[i + n - ind] = At[i] * -1;
    a[n] = -1 * At[ind];
    n++;
    algo(prv);
    reverse(a, a + n);
    algo(nex);
    reverse(nex, nex + n);
    for (ll i = 0; i < n; i++) nex[i] = n - nex[i] - 1;
    reverse(a, a + n);

    prep();
//    alog(a, n);
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++) {
        ll x = prv[i], y = nex[i];
        if (a[i] == -1 * At[ind]) continue;
        ans++;
        if (x != 0 || y != n - 1) ans++;
        ans += count_in_range(i + 1, y, a[i]);
    }

    ans += ll(count(At, At + n - 1, At[ind])) * ll((count(At, At + n - 1, At[ind]) - 1)) / 2ll;
    cout << ans << endl;

    return 0;
}