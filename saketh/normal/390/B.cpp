#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
ll v[MAXN];
ll b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
        cin >> b[i];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll v1 = b[i] / 2;
        ll v2 = (b[i] + 1) / 2;

        if (v1 == 0 || v2 > v[i]) ans--;
        else ans += v1 * v2;
    }

    cout << ans << "\n";
}