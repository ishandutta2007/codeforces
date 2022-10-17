#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    bool parity = false;
    ll tot_odd = 0, tot_even = 0;

    int type, dist;
    for (int q = 0; q < Q; q++) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &dist);

            tot_odd += dist;
            tot_even += dist;

            if (dist & 1) {
                parity = !parity;
            }
        } else {
            if (parity) {
                tot_odd++;
                tot_even--;
            } else {
                tot_odd--;
                tot_even++;
            }

            parity = !parity;
        }

        while (tot_odd >= N) tot_odd -= N;
        while (tot_odd < 0) tot_odd += N;

        while (tot_even >= N) tot_even -= N;
        while (tot_even < 0) tot_even += N;
    }

    vector<int> boy(N);

    for (int i = 0; i < N; i++) {
        int idx = i + ((i & 1) ? tot_odd : tot_even);
        if (idx >= N) idx -= N;
        boy[idx] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << boy[i] + 1 << " ";
    }

    cout << "\n";
    return 0;
}