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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, s = 0;
set<ll> poss;
map<ll, ll> mp;
vector<ll> v;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
        if (x < 0) s++;
    }

    for (int i = 1; i <= n; i++) {
        ll ans = mp[i] - mp[-1 * i] + s;
        if (ans == m) poss.insert(i);
    }

    for (ll e : v) {
        if (poss.empty()) cout << "Not defined" << endl;
        else if (e < 0 && poss.size() == 1 && poss.find(abs(e)) != poss.end()) cout << "Lie" << endl;
        else if (e < 0 && poss.find(abs(e)) == poss.end()) cout << "Truth" << endl;
        else if (e < 0) cout << "Not defined" << endl;
        else if (e > 0 && poss.find(e) == poss.end()) cout << "Lie" << endl;
        else if (e > 0 && poss.size() == 1 && poss.find(e) != poss.end()) cout << "Truth" << endl;
        else cout << "Not defined" << endl;
    }
    return 0;
}