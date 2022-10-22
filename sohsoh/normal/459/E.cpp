/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<plll> v;
ll dp[MAXN] = {0}, n, m;

vector<pll> p;

void proc() {
    for (pll e : p) dp[e.X] = max(dp[e.X], e.Y);
    p.clear();
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(all(v));
    ll prv = -1;
    for (plll e : v) {
        if (e.X != prv) proc();
        prv = e.X;
        p.push_back({e.Y.Y, max(dp[e.Y.Y], dp[e.Y.X] + 1)});
    }

    proc();
    cout << *max_element(dp, dp + MAXN) << endl;
    return 0;
}