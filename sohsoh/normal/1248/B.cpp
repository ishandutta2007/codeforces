/*
    Soheil Mohammadkhani
    Maybe candidate after this contest :)
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

const ll MAXN = 1e6; //Change me please :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> seg;

int main() {
    fast_io;
    ll n;
    cin >> n;
    deque<ll> q;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    sort(all(v));
    for (ll e : v) q.push_back(e);
    ll x = 0, y = 0;
    bool b = true;
    while (!q.empty()) {
        if (b) {
            y += q.back();
            q.pop_back();
        } else {
            x += q.front();
            q.pop_front();
        }

        b = !b;
    }

    cout << x * x + y * y << endl;
    return 0;
}