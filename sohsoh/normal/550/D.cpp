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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll k;

ll aji_maji_la_taraji(ll r) {
    cout << 1 << sep << r << endl;
    for (int i = 1; i <= k - 1; i++) cout << r << sep << r + i << endl;
    for (int j = 1; j <= k - 1; j++) for (int i = 1; i <= k - 1; i++) cout << r + j << sep << r + i + k - 1 << endl;
    for (int i = r + k; i < r + 2 * k - 2; i += 2) cout << i << sep << i + 1 << endl;
}

int main() {
    fast_io;
    cin >> k;
    if (k % 2 == 0) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    cout << k * (2 * k - 1) + 1 << sep << k * (k * (2 * k - 1) + 1) / 2 << endl;
    ll r = 2;
    for (int i = 0; i < k; i++) {
        aji_maji_la_taraji(r);
        r += 2 * k - 1;
    }

    return 0;
}