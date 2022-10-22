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

vector<ll> ans;
set<ll> st1, st2;
ll n;

int main() {
    fast_io;
    cin >> n;
    ll len = 0;
    for (int i = 0; i < n; i++) {
        len++;
        ll x;
        cin >> x;
        bool ent = (x > 0);
        ll id = abs(x);
        if (ent) {
            if (st2.find(id) != st2.end() || st1.find(id) != st1.end()) return cout << -1 << endl, 0;
            st1.insert(id);
        } else {
            st2.insert(id);
            auto it = st1.find(id);
            if (it == st1.end()) return cout << -1 << endl, 0;
            st1.erase(it);
        }

        if (st1.empty()) {
            ans.push_back(len);
            len = 0;
            st2.clear();
        }
    }

    if (len > 0) return cout << -1 << endl, 0;
    cout << ans.size() << endl;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    return 0;
}