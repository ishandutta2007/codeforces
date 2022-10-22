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
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll a[MAXN], b[MAXN], tmp_arr[MAXN];
ll res[MAXN] = {0}, res2[MAXN] = {0};

void _merge(ll s1, ll e1, ll s2, ll e2) {
    ll s = s1, e = e2, p1 = 0, p2 = 0, n = e - s, i = 0;

    while (s1 != e1 || s2 != e2) {
//        cout << s1 << " " << e1 << ", " << s2 << " " << e2 << endl;
        if (s1 != e1 && (s2 == e2 || a[s1] < a[s2])) {
            tmp_arr[i] = a[s1];
            res[a[s1].Y] += p2;
            s1++;
            p1++;
        } else {
            tmp_arr[i] = a[s2];
            s2++;
            p2++;
        }
        i++;
    }

    for (int i = s; i < e; i++) a[i] = tmp_arr[i - s];
}

void merge_sort(ll s, ll e) {
    if (e - s < 2) return;
    ll n = e - s, mid = (e - s) / 2 + s;
    merge_sort(s, mid);
    merge_sort(mid, e);
    _merge(s, mid, mid, e);
}

int main() {
    fast_io;
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i;
        b[i] = a[i];
    }

    merge_sort(0, n);
    for (int i = 0; i < n; i++) res2[i] = res[i];

    reverse(b, b + n);
    for (int i = 0; i < n; i++) {
        b[i].X *= -1;
        a[i] = b[i];
    }

    fill(res, res + n, 0);

    merge_sort(0, n);

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += res[i] * res2[i];

    cout << ans << endl;
    return 0;
}