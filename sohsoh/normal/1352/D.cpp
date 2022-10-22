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

ll solve() {
    ll n;
    cin >> n;
    deque<ll> q;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        q.push_back(k);
    }

    ll pa = 0, pb = 0;
    ll mv = 0, sa = 0, sb = 0;

    bool a_turn = true;
    while (!q.empty()) {
        if (a_turn) {
            sa += q.front();
            pa += q.front();
            q.pop_front();
        } else {
            sb += q.back();
            pb += q.back();
            q.pop_back();
        }

        if (q.empty() || (a_turn && pa > pb) || (!a_turn && pb > pa)) {
            mv++;
            a_turn = !a_turn;
            if (a_turn) pa = 0;
            else pb = 0;
        }
    }

    cout << mv << sep << sa << sep << sb << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}