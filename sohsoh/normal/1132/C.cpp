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
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> a[MAXN];

int t_arr[MAXN] = {0};
int del1[MAXN] = {0};

int main() {
    fast_io;
    ll n, q;
    cin >> n >> q;

    for (int j = 1; j <= q; j++) {
        ll l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            a[i].push_back(j);
        }
    }

    ll bf = -INF;
    for (int i = 1; i <= q; i++) {
        fill(t_arr, t_arr + q + 9, 0);
        ll emp = 0;
        ll one_rem = 0;
        for (int j = 1; j <= n; j++) {
            if (SZ(a[j]) > 2) continue;
            if (SZ(a[j]) == 2 && (a[j][0] == i || a[j][1] == i)) {
                ll s = *(a[j].begin());
                if (s == i) s = *next(a[j].begin());

                t_arr[s]++;
            } else if (SZ(a[j]) == 1 && *a[j].begin() == i) one_rem++;
            else if (SZ(a[j]) == 1) t_arr[*a[j].begin()]++;
            else if (SZ(a[j]) == 0) emp++;
        }

        int sec_rem = MAXN;
        for (int j = 1; j <= q; j++) {
            if (j == i) continue;
            sec_rem = min(sec_rem, t_arr[j]);
        }

        if (sec_rem == INF) sec_rem = 0;
        ll f = n - emp - one_rem - sec_rem;
        bf = max(bf, f);
    }

    cout << bf << endl;


    return 0;
}