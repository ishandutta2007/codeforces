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
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool eq(pair<bool, int> a, pair<bool, int> b) {
    if (a.X == b.X) {
        return true;
    }

    return false;
}

//TRUE BUS
int solve() {
    int a, b, p;
    string s;
    vector<pair<bool, int>> v;
    cin >> a >> b >> p;
    cin >> s;

    bool boo = false;


    if (s.size() == 1)
        return cout << 1 << endl, 0;
    if (s.back() != *(s.end() - 2))
        boo = true;

    int i = 1;
    for (auto it = s.begin(); it != s.end(); it++) {
        v.push_back(make_pair((*it == 'A'), i));
        i++;
    }

    auto ip = unique(v.begin(), v.end(), eq);
    v.resize(distance(v.begin(), ip));

    ll* m = new ll[v.size()];
    ll sum = 0;
    int j = v.size() - 1;
    for (auto i = v.end() - 1; i != v.begin() - 1; i--) {
        if (boo) {
            boo = false;
            j--;
            m[j] = 0;
            continue;
        }
        auto k = *i;
        if (k.first) sum += a;
        else sum += b;

        m[j] = sum;
        j--;
    }

//    alog(m, v.size());

    for (i = 0; i < v.size(); i++) {
        if (m[i] <= p) break;
    }

    if (i == v.size()) return cout << s.size() << endl, 0;
    cout << v[i].second << endl;
    return 0;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}