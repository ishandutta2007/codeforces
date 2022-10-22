/*
    Soheil Mohammadkhani
    finally, i've got candidate master, so wait for the text :|
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

const ll MAXN = 1e6 + 10; // Change this  :|
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        queue<pll> neg;
        ll ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') ans--;
            else ans++;
            if (ans < 0) neg.push({ans, i});
        }

        ll i = 0;
        ans = 0;
        while (!neg.empty()) {
            while (!neg.empty() && neg.front().X + i >= 0) neg.pop();
            ll x = 0;
            if (!neg.empty()) x = neg.front().Y + 1;
            ans += x;
            i++;
        }

        cout << ans + n << endl;
    }
    return 0;
}