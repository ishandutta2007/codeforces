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

map<ll, ll> mp;
ll n, m, ans = 0;
ll A[MAXN], B[MAXN], C[MAXN], t_arr[MAXN];

void m_merge(ll s1, ll e1, ll s2, ll e2) {
    ll p1 = s1, p2 = s2;
    ll ind = 0;
    while (p1 < e1 || p2 < e2) {
        if (p1 < e1 && (p2 >= e2 || A[p1] < A[p2])) {
            t_arr[ind] = A[p1];
            ans += p2 - s2;
            p1++;
        } else {
            t_arr[ind] = A[p2];
            p2++;
        }

        ind++;
    }

    for (int i = s1; i < e2; i++) A[i] = t_arr[i - s1];
}

ll li(ll x) {
    ll l = 0, h = m - 1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (A[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

ll ui(ll y) {
    ll l = 0, h = m - 1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (A[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

ll rng(ll x, ll y) {
    return ui(y) - li(x) + 1;
}

void merge_sort(ll s, ll e) {
    ll n = e - s;
    if (n < 2) return;
    merge_sort(s, s + (n / 2));
    merge_sort(s + n / 2, e);
    m_merge(s, s + n / 2, s + n / 2, e);
}

int main() {
    cin >> n;
    for (int k = 0; k < n; k++) {
        ll i, j;
        cin >> i >> j;
        if (mp.find(i) == mp.end()) mp.insert({i, i});
        if (mp.find(j) == mp.end()) mp.insert({j, j});
        swap(mp[i], mp[j]);
    }

    m = 0;
    for (pll e : mp) {
        A[m] = e.Y;
        C[m] = e.Y;
        B[m] = e.X;
        m++;
    }

    merge_sort(0, m);
    for (int i = 0; i < m; i++) {
        ll ind = B[i], x = C[i];
        if (x < ind) {
            ans += min(ind - x + 1, ind);
            ans -= rng(x, ind);
        } else if (x > ind) {
            ans += min(x - ind + 1, x);
            ans -= rng(ind, x);
        }
    }

    cout << ans << endl;
    return 0;
}