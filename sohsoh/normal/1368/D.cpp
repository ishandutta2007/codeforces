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

const ll MAXN = 1e6 + 10; //change this
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 21;

ll cnt[LOG] = {0};
bitset<LOG> ans[MAXN];

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll j = 0;
        while (x > 0) {
            cnt[j] += x % 2;
            x /= 2;
            j++;
        }
    }

    for (int i = LOG - 1; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            ans[j][i] = 1;
        }
    }

    ll sum = 0;
    for (int i = 0; i < MAXN; i++) {
        ll x = ans[i].to_ullong();
        sum += x * x;
    }

    cout << sum << endl;
    return 0;
}