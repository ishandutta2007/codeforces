/*
    Soheil Mohammadkhani
    FROM virus-table SELECT * WHERE id=19
    -> COVID19 :|
    IDK Why im writing this shitty quotes :|
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
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int solve() {
//    cout << "LE" << endl;
    ll n;
    cin >> n;

    int* a = new int[n];
    set<int> h;
    ll cnt[2000] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        h.insert(a[i]);
    }

    ll m = *max_element(cnt, cnt + 2000);
    for (int x : h) {

//    cout << x << endl;
        ll tmp_cnt[2000] = {0};
        ll tmp_max = 0;
        ll ac = cnt[x] / 2;
        stack<int> start;
        stack<int> en;
        for (int i = 0; i < n && start.size() < ac; i++) {
            if (a[i] == x) start.push(i);
        }

        for (int i = n - 1; i >= 0 && en.size() < ac; i--) {
            if (a[i] == x) en.push(i);
        }

        ll prev_start = -1;
        ll prev_end = -1;

        ll j = 1;
        while (!start.empty()) {
            ll f = start.top();
            ll t = en.top();
            start.pop();
            en.pop();
            if (prev_end == -1) {
                for (int i = f; i <= t; i++) {
                    if (a[i] == x) continue;
                    tmp_cnt[a[i]]++;
                    tmp_max = max(tmp_cnt[a[i]], tmp_max);
                }
            } else {
                for (int i = f; i < prev_start; i++) {
                    if (a[i] == x) continue;
                    tmp_cnt[a[i]]++;
                    tmp_max = max(tmp_cnt[a[i]], tmp_max);
                }

                for (int i = prev_end + 1; i <= t; i++) {
                    if (a[i] == x) continue;
                    tmp_cnt[a[i]]++;
                    tmp_max = max(tmp_cnt[a[i]], tmp_max);
                }
            }

            prev_start = f;
            prev_end = t;
            m = max(m, 2 * ac + tmp_max);
//            if (m == 6) {bug(tmp_max) alog(tmp_cnt, 4)}
            ac--;
        }

//    cout << x << endl;
    }

    cout << m << endl;

    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
//    t = 1;//DEBUG
    while (t--) {
        solve();
    }
    return 0;
}