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

const ll MAXN = 2000 + 110;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll seq[MAXN] = {0}, s = 0;

bool subsett[MAXN][MAXN];
bool check(ll sett[], ll n, ll sum)
{
    for (int i = 0; i <= n; i++)
        subsett[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subsett[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < sett[i - 1])
                subsett[i][j] = subsett[i - 1][j];
            if (j >= sett[i - 1])
                subsett[i][j] = subsett[i - 1][j]
                               || subsett[i - 1][j - sett[i - 1]];
        }
    }
    return subsett[n][sum];
}




ll solve() {
    ll t = 0, m = 0, n;
    s = 0;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        ll x;
        cin >> x;
        if (x > m) {
            seq[s] = t;
            s++;
            t = 0;
            m = x;
        }

        t++;
    }

    seq[s] = t;
    s++;

    if (check(seq, s + 10, n) > 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i = 0; i < s + 100; i++) seq[i] = 0;

    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}