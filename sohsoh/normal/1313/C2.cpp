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

ll n;
ll a[MAXN], prv_min[MAXN], nxt_min[MAXN];
ll dp_f[MAXN], dp_b[MAXN];

void min_stack(ll* b) {
    stack<int> prv;
    for (int i = 0; i < n; i++) {
        while (!prv.empty() && a[prv.top()] >= a[i]) {
            prv.pop();
        }

        if (prv.empty()) b[i] = -1;
        else b[i] = prv.top();

        prv.push(i);
    }
}

void solve(int ind) {
    int* res = new int[n];
    ll m = a[ind];
    res[ind] = a[ind];
    for (int i = ind - 1; i >= 0; i--) {
        m = min(m, a[i]);
        res[i] = m;
    }

    m = a[ind];
    for (int i = ind + 1; i < n; i++) {
        m = min(m, a[i]);
        res[i] = m;
    }

    alog(res, n);
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    min_stack(prv_min);
    reverse(a, a + n);
    min_stack(nxt_min);
    reverse(nxt_min, nxt_min + n);
    reverse(a, a + n);

    for (int i = 0; i < n; i++) nxt_min[i] = n - nxt_min[i] - 1;

    // LETS START FROM HERE :)
    dp_b[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (prv_min[i] == -1) dp_b[i] = (i + 1) * a[i];
        else {
            dp_b[i] = dp_b[prv_min[i]] + (i - prv_min[i]) * a[i];
        }
    }

    dp_f[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nxt_min[i] == n) dp_f[i] = (n - i) * a[i];
        else {
            dp_f[i] = dp_f[nxt_min[i]] + (nxt_min[i] - i) * a[i];
        }
    }

    int best_ind = 0;
    ll best = 0;
    for (int i = 0; i < n; i++) {
        if (dp_f[i] + dp_b[i] - a[i] > best) {
            best = dp_f[i] + dp_b[i] - a[i];
            best_ind = i;
        }
    }

    solve(best_ind);
    return 0;
}