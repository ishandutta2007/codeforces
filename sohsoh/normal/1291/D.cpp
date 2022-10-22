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

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN][26] = {0};
ll a[MAXN] = {0};

int main() {
    fast_io;
    string s;
    cin >> s;
    ll i = 1;
    for (char c : s) {
        cnt[i][c - 'a']++;
        for (int j = 0; j < 26; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }

        a[i] = c - 'a';

        i++;
    }

    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (l == r || a[l] != a[r]) {
            cout << "YES" << endl;
            continue;
        }

        ll dis_char = 0;
        for (int j = 0; j < 26; j++) {
            ll s = cnt[r][j];
            s -= cnt[l - 1][j];
            if (s > 0) dis_char++;
        }

        if (dis_char >= 3) {
            cout << "YES" << endl;
            continue;
        }


        cout << "NO" << endl;
    }
    return 0;
}