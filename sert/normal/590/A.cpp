#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k;
ll ans;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = 0;
    a[n] = a[n - 1];
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
            k++;
        } else if (k > 0) {
            ans = max(ans, (k + 1) / 2);
            if (k % 2 == 0) {
                for (int j = i - k; j < i - k / 2; j++)
                    a[j] = 1 - a[i];
                for (int j = i - k / 2; j < i; j++)
                    a[j] = a[i];
            } else {
                for (int j = i - k; j < i; j++)
                    a[j] = a[i];
            }
            k = 0;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}