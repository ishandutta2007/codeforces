#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int N, K, S;

int loq[155];
int ans[155][155 * 155];

int main() {
    cin >> N >> K >> S;
    for (int i = 0; i < N; i++)
        cin >> loq[i];

    S += K * (K - 1) / 2;
    S = min(S, N * (N - 1) / 2);

    memset(ans, 0x7f, sizeof(ans));
    memset(ans[0], 0, sizeof(ans[0]));

    for (int i = 0; i < N; i++)
        for (int p = K; p >= 1; p--)
            for (int c = S; c >= i; c--)
                ans[p][c] = min(ans[p][c], ans[p-1][c-i] + loq[i]);

    int res = INF;
    for (int c = 0; c <= S; c++)
        res = min(res, ans[K][S]);
    cout << res << "\n";
}