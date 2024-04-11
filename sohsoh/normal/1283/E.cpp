/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[MAXN], cnt[MAXN] = {0}, n;
vector<ll> v;

ll mn() {
    ll ans = 0;
    ll op = 0;
    vector<ll> v_ans;
    for (auto it = v.begin(); it != v.end(); it++) {
        ll now = *it;

        if (!v_ans.empty() && now - v_ans.back() < 2) v_ans.push_back(v_ans.back());
        else v_ans.push_back(now + 1);
    }

    Sort(v_ans);
    auto ip = unique(all(v_ans));
    return distance(v_ans.begin(), ip);
}

ll mx() {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll e = a[i];
        if (cnt[e - 1] == 0) {
            cnt[e - 1]++;
            ans++;
            continue;
        }

        if (cnt[e] == 0) {
            cnt[e]++;
            ans++;
            continue;
        }

        if (cnt[e + 1] == 0) {
            cnt[e + 1]++;
            ans++;
            continue;
        }
    }

    return ans;
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(a, a + n);
    Sort(v);
    auto ip = unique(all(v));
    v.resize(distance(v.begin(), ip));

    cout << mn() << sep << mx() << endl;
    return 0;
}