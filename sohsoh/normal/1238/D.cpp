/*
    Soheil Mohammadkhani
    Maybe candidate after this contest :)
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

const ll MAXN = 1e6; //Change me please :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> seg;

int main() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) ans++;
        else {
            seg.push_back(ans);
            ans = 1;
        }
    }

    seg.push_back(ans);
    ans = 0;
    for (int i = 1; i < seg.size(); i++) {
        ans += seg[i];
        ans += seg[i - 1];
        ans--;
    }

    cout << n * (n - 1) / 2 - ans << endl;
    return 0;
}