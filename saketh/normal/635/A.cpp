#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3050;

int R, C, N, K;
int r[MAXN], c[MAXN];
vector<int> in_row[MAXN];

int V;
int rev[MAXN];
int who[MAXN];
int far[MAXN];
int pred[MAXN];
int succ[MAXN];

int weight(int lli) {
    if (pred[lli] == 0) return c[who[lli]];
    return c[who[lli]] - c[who[pred[lli]]];
}

int avail(int lli) {
    if (lli > V) return 0;
    return C + 1 - c[who[lli]];
}

int contrib(int lli) {
    if (lli <= 0 || lli > V) return 0;
    return weight(lli) * avail(far[lli]);
}

ll solve(int r0) {
    vector<int> violas;

    for (int r = r0; r <= R; r++) {
        for (int i : in_row[r])
            violas.push_back(i);
    }

    V = violas.size();
    sort(violas.begin(), violas.end(), [](int i, int j){
        if (c[i] != c[j]) return c[i] < c[j];
        return r[i] < r[j];
    });

    ll total = 0, cur = 0;

    for (int i = 1; i <= V; i++) {
        who[i] = violas[i - 1];
        rev[who[i]] = i;
        pred[i] = i - 1;
        succ[i] = i + 1;
        far[i] = min(V + 1, i + K - 1);
    }

    pred[0] = 0;
    succ[V + 1] = V + 1;

    for (int i = 1; i <= V; i++) {
        cur += contrib(i);
    }

    total += cur;

    for (int r = R; r > r0; r--) {
        for (int i : in_row[r]) {
            int lli = rev[i];

            if (succ[lli] != V + 1) {
                cur -= contrib(succ[lli]);
                pred[succ[lli]] = pred[lli];
                cur += contrib(succ[lli]);
            }

            cur -= contrib(lli);

            if (pred[lli] != 0) {
                int tail = pred[lli];
                succ[tail] = succ[lli];

                for (int j = 0; j < K - 1; j++) {
                    cur -= contrib(tail);
                    far[tail] = succ[far[tail]];
                    cur += contrib(tail);

                    if (tail == 0) break;
                    tail = pred[tail];
                }
            }
        }

        total += cur;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> R >> C >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> r[i] >> c[i];
        in_row[r[i]].push_back(i);
    }

    ll ans = 0;

    for (int r0 = 1; r0 <= R; r0++) {
        ans += solve(r0);
    }

    cout << ans << "\n";

    return 0;
}