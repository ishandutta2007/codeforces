#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "map"

using namespace std;

typedef long long ll;
typedef long double fr;
typedef string str;
typedef pair<ll, ll> node;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define for0(i, n) for (ll i = 0; i < n; ++i)
#define for1(i, n) for (ll i = 1; i < n; ++i)
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define forll(i, a, n) for (ll i = a; i < n; ++i)
#define lout(A) for (auto i : A) cout << i << " "; cout << endl;
#define lin(A) for (auto &i : A) cin >> i;
const ll INF = 1e18+7;
const fr eps = 1e-6;

void build_tree(ll v, ll l, ll r, vector<ll> &A, vector<ll> &tree) {
    if (l == r) {
        tree[v] = A[l];
    } else {
        ll m = (r + l) / 2;
        build_tree(v * 2 + 1, l, m, A, tree);
        build_tree(v * 2 + 2, m + 1, r, A, tree);
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }

}
ll find_max(ll v, ll al, ll ar, ll l, ll r, vector<ll> &tree) {
    if (l == al && r == ar) {
        return tree[v];
    } else {
        ll m = (r + l) / 2, res1 = 0, res2 = 0;
        if (al <= m)
            res1 = find_max(v * 2 + 1, al, min(ar, m), l, m, tree);
        if (ar > m)
            res2 = find_max(v * 2 + 2, max(m + 1, al), ar, m + 1, r, tree);
        return max(res1, res2);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> A(m);
    lin(A);
    vector<ll> tree(4*m);
    build_tree(0, 0, m - 1, A, tree);
    //lout(tree);
    //find_max(0, x, y, 0, m, tree);
    ll q;
    cin >> q;
    while (q--) {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        --a, --b, --c, --d;
        a %= k, c %= k;
        a = (n - 1) / k * k + (a % k);
        if (a >= n)
            a -= k;
        c = (n - 1) / k * k + (c % k);
        if (c >= n)
            c -= k;
        a++;c++;
        if (b > d) {
            swap(b, d);
            swap(a, c);
        }
        ll e = find_max(0, b, d, 0, m - 1, tree);
        //cout << a << endl;
        if (a == c && a > e && abs(b - d) % k == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}