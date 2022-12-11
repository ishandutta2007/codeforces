#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, l, r, x, sum, ans;
vector <int> p;
ll a[N];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int mask = 0; mask < (1 << n); mask++) {
        p.clear();
        sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) {
                p.push_back(a[i]);
                sum += a[i];
            }
        sort(p.begin(), p.end());
        if (l <= sum && sum <= r && p.back() - p[0] >= x)
            ans++;
    }

    cout << ans;

    return 0;
}