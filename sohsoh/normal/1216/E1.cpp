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

const ll MAXN = 536870912; // finally found it :)
const ll INF = 1e9 + 100;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll sum(ll n, ll c) {return n * (n + 1) / 2 - (n - c) * (n - c + 1) / 2;}

ll cnt(ll n) {
    if (n == 1) return 0;
    ll p = 10, prev = 0, dig = 1, ans = 0, tmp = n;
    while (p <= n) {
        ans += dig * sum(tmp, p - prev - 1);
        tmp -= p - prev - 1;
        prev = p - 1;
        p *= 10;
        dig++;
    }

    ll x = n - prev - 1;
    ans += dig * sum(tmp, x);
    return ans;
}

ll cnt2(ll n) {
    if (n == 1) return 0;
    ll p = 10, prev = 0, dig = 1, ans = 0, tmp = n;
    while (p <= n) {
        ans += dig * (p - prev - 1);
        tmp -= p - prev - 1;
        prev = p - 1;
        p *= 10;
        dig++;
    }

    ll x = n - prev - 1;
    ans += dig * x;
    return ans;
}

int main() {
    fast_io;
    ll q;
    cin >> q;
    while (q--) {
        ll L = 1, R = MAXN, k;
        cin >> k;
        while (L < R) {
            ll mid = ceil((L + R) / ld(2));
            if (cnt(mid) < k) L = mid;
            else R = mid - 1;
        }

        vector<ll> dig;
        while (R > 0) {
            dig.push_back(R % 10);
            R /= 10;
        }

        k -= cnt(L);
        if (k <= dig.size()) {
            reverse(all(dig));
            cout << dig[k - 1] << endl;
            continue;
        }

        k -= dig.size();
        R = L;
        L = 1;
        while (L < R) {
            ll mid = ceil((L + R) / ld(2));
            if (cnt2(mid) < k) L = mid;
            else R = mid - 1;
        }

        dig.clear();
        while (R > 0) {
            dig.push_back(R % 10);
            R /= 10;
        }

        reverse(all(dig));
        cout << dig[k - cnt2(L) - 1] << endl;

    }
    return 0;
}