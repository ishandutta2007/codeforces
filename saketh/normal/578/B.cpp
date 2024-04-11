#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;

int N, K, X;
ll val[MAXN];
ll lef[MAXN];
ll rig[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K >> X;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    for (int i = 1; i < N; i++) {
        lef[i] = lef[i-1] | val[i-1];
    }

    for (int i = N - 2; i >= 0; i--) {
        rig[i] = rig[i+1] | val[i+1];
    }

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ll cand = val[i];
        for (int i = 0; i < K; i++)
            cand *= X;

        cand |= lef[i];
        cand |= rig[i];

        ans = max(ans, cand);
    }

    cout << ans << "\n";
}