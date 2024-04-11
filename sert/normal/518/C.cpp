#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll n, m, k, num, ps, ans;
ll a[N], p[N];

ll cnt(ll ps) {
    return 1 + ps / k;
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> num;
        p[i] = num - 1;
        a[num - 1] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> num;
        num--;
        ps = a[num];
        ans += cnt(ps);
        if (ps == 0) continue;
        swap(p[ps], p[ps - 1]);
        a[p[ps - 1]] = ps - 1;
        a[p[ps]] = ps;
    }
    cout << ans;
    //return 0;
}