#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

string s;
ll n, m, k, t, p, q, l, r;
ll a[N], b[N], c[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        b[l - 1]++;
        b[r]--;
    }
    for (int i = 0; i < n; i++) {
        q += b[i];
        c[i] = q;
    }
    sort(c, c + n);
    for (int i = 0; i < n; i++) k += c[i] * a[i];
    cout << k << "\n";
    return 0;
}