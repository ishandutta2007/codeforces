#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll n, x;
ll k1, k2;
ll p[1000];
pair <ll, ll> a[1000];

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i].second;
        if (a[i].first < 0)
            k1 = i + 1;
    }

    k2 = n - k1;

    //cerr << k1 << " " << k2 << "\n";

    if (k1 < k2)
        cout << p[k1 * 2 + 1];
    else if (k1 == k2)
        cout << p[n];
    else
        cout << p[n] - p[k1 - k2 - 1];

    return 0;
}