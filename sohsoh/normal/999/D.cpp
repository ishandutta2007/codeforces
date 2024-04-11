/*
    Soheil Mohammadkhani
    Loading Text ... please wait
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

//KeepCalm and just code until the contest :|
ll n, m, b = 0, ans = 0, a[MAXN], cnt[MAXN] = {0};
set<ll> st;

int main() {
    cin >> n >> m;
    b = n / m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % m]++;
    }

    for (int i = 0; i < m; i++) {
        if (cnt[i] < b) st.insert(i);
    }

    for (int i = 0; i < n; i++) {
        ll md = a[i] % m;
        if (cnt[md] <= b) continue;
        auto it = st.lower_bound(md);
        ll dist;

        if (it == st.end()) {
            it = st.begin();
            dist = m - md + *it;
        } else dist = *it - md;

        ans += dist;
        a[i] += dist;
        cnt[*it]++;
        cnt[md]--;
        if (cnt[*it] == b) st.erase(it);
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << sep;
    }

    cout << endl;
    return 0;
}