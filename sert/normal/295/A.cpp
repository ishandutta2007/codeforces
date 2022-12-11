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

const ll N = 1e5 + 34;

ll a[N], l[N], r[N], d[N], b[N], c[N];
ll n, m, k, x, y, q, ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &l[i], &r[i], &d[i]);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        b[x - 1]++;
        b[y]--;
    }
    for (int i = 0; i < m; i++) {
        q += b[i];
        d[i] *= q;
    }
    for (int i = 0; i < m; i++) {
        c[l[i] - 1] += d[i];
        c[r[i]] -= d[i];
    }
    q = 0;
    for (int i = 0; i < n; i++) {
        q += c[i];
        cout << q + a[i] << " ";
    }

    return 0;
}