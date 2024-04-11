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

const ll MAXN = 3e5 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], red[MAXN] = {0};
vector<ll> pos[MAXN];

int main() {
    fast_io;
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> A[i], pos[A[i]].push_back(i);
    for (int i = 0; i < m - 1; i++) {
        pll p = {A[i], A[i + 1]};
        if (p.X > p.Y) swap(p.X, p.Y);
        if (p.Y - p.X < 2) continue;
        red[p.Y]--;
        red[p.X + 1]++;
    }

    for (int i = 1; i <= n; i++) red[i] += red[i - 1];
//    alog(red, n + 1)
    ll base = 0;
    for (int i = 0; i < m - 1; i++) base += abs(A[i] - A[i + 1]);
    cout << base << sep;
    for (int i = 2; i <= n; i++) {
        ll ans = base;
        for (ll ind : pos[i]) {
            if (ind > 0) ans -= abs(A[ind] - A[ind - 1]);
            if (ind + 1 < m) ans -= abs(A[ind] - A[ind + 1]);
            if (ind + 1 < m && A[ind + 1] != A[ind]) {
                ll pos = A[ind + 1];
                if (i > pos) pos++;
                ans += pos - 1;
            }

            if (ind > 0 && A[ind] != A[ind - 1]) {
                ll pos = A[ind - 1];
                if (i > pos) pos++;
                ans += pos - 1;
            }
        }

        cout << ans - red[i] << sep;
    }

    cout << endl;
    return 0;
}