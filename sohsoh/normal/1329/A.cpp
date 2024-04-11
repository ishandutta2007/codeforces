/*
    Soheil Mohammadkhani
    IDK :)
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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define wrong                       return cout << -1 << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    ll* a = new ll[m];
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll hid = sum - n;
    if (hid < 0) wrong;

    reverse(a, a + m);
    stack<ll> col;
    col.push(a[0]);

    ll total_colored = a[0];

    for (int i = 1; i < m; i++) {
        ll new_hid = min(hid, a[i] - 1);
        new_hid = min(new_hid, total_colored);
        col.push(a[i] - new_hid);
        total_colored += a[i] - new_hid;
        hid -= new_hid;
    }

    ll point = 0;
    queue<ll> res;
    while (!col.empty()) {
        res.push(point);
        point += col.top();
        col.pop();
    }

    if (res.back() + a[0] != n) wrong;

    while (!res.empty()) {
        cout << res.front() + 1 << sep;
        res.pop();
    }
    cout << endl;
    return 0;
}