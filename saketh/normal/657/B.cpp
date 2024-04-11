#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;

ll N, K;
ll poly[MAXN];
ll bef[MAXN];
ll aft[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;
    N++;

    for (int i = 0; i < N; i++) {
        cin >> poly[i];
    }

    fill(bef, bef + MAXN, LLONG_MAX);
    fill(aft, aft + MAXN, LLONG_MAX);

    bef[0] = 0;
    for (int i = 1; i < N; i++) {
        ll prv = bef[i-1] + poly[i-1];
        if (prv & 1) break;
        bef[i] = prv / 2;
    }

    aft[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
        ll nxt = 2 * aft[i+1] + poly[i+1];
        if (abs(nxt) > K) break;
        aft[i] = nxt;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (bef[i] == LLONG_MAX || aft[i] == LLONG_MAX) continue;

        ll tot = abs(bef[i] + 2 * aft[i]);

        if (i == N - 1 && tot == 0) continue;
        if (tot <= K) ans++;
    }

    cout << ans << "\n";
}