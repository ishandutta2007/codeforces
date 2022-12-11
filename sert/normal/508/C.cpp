#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 2011;
const ll md = 1e9 + 7;

ll m, t, r, ans, k;
ll a[N], s[N];
bool u[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> m >> t >> r;
    
    if (r > t) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i] += 340;
    }

    for (int i = 0; i < m; i++) {
        k = r - s[a[i]];
        for (int j = a[i]; k; j--)
            if (!u[j]) {
                k--;
                u[j] = false;
                for (int k = j; k < j + t; k++)
                    s[k]++;
                ans++;
            }
    }

    cout << ans;

    //return 0;
}