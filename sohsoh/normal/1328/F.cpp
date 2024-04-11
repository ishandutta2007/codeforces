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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
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
const ll MOD = 998244353 ; // 1e9 + 9;

map<ll, ll> cnt;
ll dp_l[MAXN] = {0}, dp_r[MAXN] = {0}, cnt_l[MAXN] = {0}, cnt_r[MAXN] = {0};
ll n, k;

int main() {
//    fast_io;
    cin >> n >> k;
    ll* a = new ll[n];
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        if (cnt.find(a[i]) == cnt.end()) {
            cnt.insert({a[i], 0});
        }
        cnt[a[i]]++;
    }

    sort(a, a + n);
    Sort(v);
    auto ip = unique(all(v));
    v.resize(distance(v.begin(), ip));

    cnt_l[0] = cnt[v.front()];
    cnt_r[SZ(v) - 1] = cnt[v.back()];
    for (int i = 1; i < SZ(v); i++) {
        ll prev = v[i - 1], now = v[i];
        dp_l[i] = dp_l[i - 1] + (now - prev) * (cnt_l[i - 1]);
        cnt_l[i] = cnt_l[i - 1] + cnt[now];
    }

    for (int i = SZ(v) - 2; i >= 0; i--) {
        ll prev = v[i + 1], now = v[i];
        dp_r[i] = dp_r[i + 1] + (prev - now) * (cnt_r[i + 1]);
        cnt_r[i] = cnt_r[i + 1] + cnt[now];
    }

    ll bf = INF;
    for (int i = 0; i < SZ(v); i++) {
        ll tk = k, now = v[i];
        ll c = cnt[now];
        if (c >= k) kill(0);
        tk -= c;

        pll ans = {INF, INF};
        if (cnt_l[i] - c >= tk) {
            ll ac = cnt_l[i] - c;
            ans.X = dp_l[i] - (ac - tk);
        }

        if (cnt_r[i] - c >= tk) {
            ll ac = cnt_r[i] - c;
            ans.Y = dp_r[i] - (ac - tk);
        }

        bf = min(bf, ans.X);
        bf = min(bf, ans.Y);

        ll ans2 = 0;
        ans2 += dp_l[i] - (cnt_l[i] - c);
        ans2 += dp_r[i] - (cnt_r[i] - c);
        ans2 += tk;

        bf = min(bf, ans2);
    }

    cout << bf << endl;

    return 0;
}