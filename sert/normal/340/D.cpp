#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll p = 131072;

ll a[N];
ll b[N];
ll c[N];
ll n, k, t, h, m;
string s;

ll get_min(int v, int l, int r, int L, int R) {
    if (L >= r || R <= l)
        return 0;
    if (r - l == 1)
        return c[v];
    if (l >= L && r <= R)
        return c[v];
    int m = (l + r) / 2;
    int v1 = get_min(v * 2 + 1, l, m, L, R);
    int v2 = get_min(v * 2 + 2, m, r, L, R);
    return max(v1, v2);
}

void change(int v, int l, int r, int p, int x) {
    if (r - l == 1) {
        c[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        change(v * 2 + 1, l, m, p, x);
    else
        change(v * 2 + 2, m, r, p, x);
    c[v] = max(c[v * 2 + 1], c[v * 2 + 2]);
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, p * 2)
        c[i] = 0;
    for (int i = 0; i < n; i++) {
        t = get_min(0, 0, n, 0, a[i]);
        b[i] = t + 1;
        change(0, 0, n, a[i] - 1, t + 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, b[i]);

    cout << ans;

    return 0;
}