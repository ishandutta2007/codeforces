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

const ll MAXN = 2000 + 10; // Change it
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> v;

bool is_prime(ll x) {
    ll sq = sqrt(x);
    if (x == 1) return false;
    for (int i = 2; i <= sq; i++) if (x % sq == 0) return false;
    return true;
}

ll A[MAXN];
vector<ll> cnt[MAXN];

void solve() {
    ll n;
    cin >> n;
    n *= 2;
    vector<ll> e, o;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2) o.push_back(i + 1);
        else e.push_back(i + 1);
    }


        bool b = true;
        if (e.size() % 2) {
            b = false;
            e.pop_back();
        }


        if (o.size() % 2) {
            b = false;
            o.pop_back();
        }

        if (b) {
            if (o.size() > 0) {
                o.pop_back();
                o.pop_back();
            } else {
                e.pop_back();
                e.pop_back();
            }
        }

        for (int i = 0; i < e.size(); i += 2) {
            cout << e[i] << sep << e[i + 1] << endl;
        }


        for (int i = 0; i < o.size(); i += 2) {
            cout << o[i] << sep << o[i + 1] << endl;
        }
}

int main() {
    fast_io;
    ll t;
    cin >> t;

    for (int i = 1; i <= MAXN; i++) if (is_prime(i)) v.push_back(i);
    while (t--) solve();
    return 0;
}