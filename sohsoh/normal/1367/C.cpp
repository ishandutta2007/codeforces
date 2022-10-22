/*
    Soheil Mohammadkhani
    div 3 contest :)
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

const ll MAXN = 1e6 + 10; //Change this bullshit :| to prevent all of the runtimes :|
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        ll len = 0;
        int i;
        for (i = 0; i < n; i++)  {
            if (s[i] == '1') break;
            len++;
        }

        ll ans = len / (k + 1);
        if (len == n) {
            cout << ceil(len / ld(k + 1)) << endl;
            continue;
        }

        len = 0;

        ll st = i + 1;
        for (i = n - 1; i >= 0; i--) {
            if (s[i] == '1') break;
            len++;
        }

        ll e = i;
        ans += len / (k + 1);
        len = 0;
        for (int i = st; i <= e; i++) {
            if (s[i] == '1') {
                len -= k;
                ans += max(len / (k + 1), 0ll);
                len =  0;
            } else len++;
        }

        cout << ans << endl;
    }
    return 0;
}