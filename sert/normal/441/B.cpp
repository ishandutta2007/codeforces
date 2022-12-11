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

ll t, b, n, a, mn;
ll k[N], ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        k[a] += b;
    }

    for (int i = 1; i < 3330; i++) {
        mn = min(t, k[i] + k[i - 1]);
        ans += mn;
        if (mn > k[i - 1])
            k[i] -= (mn - k[i - 1]);
    }

    cout << ans;

    return 0;
}