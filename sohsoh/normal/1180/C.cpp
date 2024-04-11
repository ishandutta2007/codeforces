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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, res2[MAXN];
deque<ll> d;
pll res1[MAXN];

int main() {
    fast_io;
    cin >> n >> q;
    ll m = 0;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        m = max(k, m);
        d.push_back(k);
    }

    ll x = 0;
    while (d.front() != m) {
        ll A = d.front();
        d.pop_front();
        ll B = d.front();
        d.pop_front();

        res1[x] = {A, B};

        d.push_front(max(A, B));
        d.push_back(min(A, B));
        x++;
    }

    d.pop_front();
    for (int i = 0; i < n - 1; i++) {
        res2[i] = d.front();
        d.pop_front();
    }

    while (q--) {
        ll k;
        cin >> k;
        k--;
        if (k < x) {
            cout << res1[k].X << " " << res1[k].Y << endl;
            continue;
        }

        k -= x;
        k %= (n - 1);
        cout << m << " " << res2[k] << endl;
    }
    return 0;
}