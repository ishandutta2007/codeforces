#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N, bridge[MAXN];
ll down[MAXN][3], up[MAXN][3];

int win(int strength, bool ret) {
    if(ret) return strength - (strength & 1);
    if(strength & 1) return strength;
    return strength - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> bridge[i];

        down[i][0] = win(bridge[i], false) + down[i-1][2];
        if(bridge[i] >= 2) down[i][1] = win(bridge[i], true) + down[i-1][1];
        down[i][2] = max(down[i][0], down[i][1]);
    }

    for (int i = N - 2; i >= 0; i--) {
        up[i][0] = win(bridge[i+1], false) + up[i+1][2];
        if(bridge[i+1] >= 2) up[i][1] = win(bridge[i+1], true) + up[i+1][1];
        up[i][2] = max(up[i][0], up[i][1]);
    }

    ll best = 0;

    for (int start = 0; start < N; start++) {
        // must return from left
        ll cand1 = up[start][2];
        if(start > 0) cand1 += down[start][1];

        // must return from right
        ll cand2 = down[start][2];
        if(start + 1 < N) cand2 += up[start][1];

        best = max(best, max(cand1, cand2));
    }

    cout << best << "\n";
}