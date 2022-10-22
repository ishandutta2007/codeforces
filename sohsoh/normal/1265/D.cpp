/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> p1, p2, p3;
ll ans[MAXN];

int main() {
    fast_io;
    ll a, b, c, d, pa, pb, pc, pd, n;
    cin >> a >> b >> c >> d;
    pa = a; pb = b; pc = c; pd = d; n = a + b + c + d;

    while (a > 0) {
        if (p1.empty() || p1.back() == 1) {
            p1.push_back(0);
            a--;
        } else {
            p1.push_back(1);
            b--;
        }
    }

    while (d > 0) {
        if (p3.empty() || p3.back() == 2) {
            p3.push_back(3);
            d--;
        } else {
            p3.push_back(2);
            c--;
        }
    }

    if (!p3.empty() && p3.back() == 3 && c > 0) {
        p3.push_back(2);
        c--;
    }

    if (!p1.empty() && p1.back() == 0 && b > 0) {
        p1.push_back(1);
        b--;
    }
    reverse(all(p3));

    while (b > 0 && c > 0) {
        p2.push_back(2);
        p2.push_back(1);
        b--;
        c--;
    }


    if (b == 1) {
        p1.insert(p1.begin(), 1);
        b--;
    }

    if (c == 1) {
        p3.push_back(2);
        c--;
    }

    if (b != 0 || c != 0 || SZ(p1) + SZ(p2) + SZ(p3) != n) kill("NO");

    ll x = 0;
    for (ll e : p1) {
        ans[x] = e;
        x++;
    }

    for (ll e : p2) {
        ans[x] = e;
        x++;
    }

    for (ll e : p3) {
        ans[x] = e;
        x++;
    }

    for (int i = 1; i < n; i++) {
        if (abs(ans[i] - ans[i - 1]) != 1) {
            kill("NO")
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << sep;
    cout << endl;
    return 0;
}