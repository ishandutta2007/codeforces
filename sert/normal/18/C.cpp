#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 34;

ll p[N], s[N], a[N], n, ans;

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[n - i];

    for (int i = 1; i < n; i++)
        if (p[i] == s[n - i])
            ans++;

    cout << ans;

    //while(true);
}