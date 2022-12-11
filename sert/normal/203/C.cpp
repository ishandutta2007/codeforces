#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 7;

pair <ll, ll> a[N];
ll len, n, d, aa, bb;
ll ans[N];

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return y.second > x.second;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> d;
    cin >> aa >> bb;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first = a[i].first * aa + bb * a[i].second;
        a[i].second = i + 1;
    }
    sort(a, a + n);

    while (d >= a[len].first) {
        d -= a[len].first;
        ans[len++] = a[len].second;
        if (len == n)
            break;
    }


    cout << len << "\n";
    for (int i = 0; i < len; i++)
        printf("%I64d ", ans[i]);

    return 0;
}