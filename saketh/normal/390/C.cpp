#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N, K, W;
bool candy[MAXN];

int pref[MAXN];
int sum[MAXN][10];
int qua[MAXN][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K >> W;

    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        candy[i] = (c == '1');

        pref[i] = pref[i-1] + int(candy[i]);

        for (int r = 0; r < K; r++) {
            sum[i][r] = sum[i-1][r];
            qua[i][r] = qua[i-1][r];
        }

        sum[i][i%K]+= int(candy[i]);
        qua[i][i%K]++;
    }

    for (int i = 0; i < W; i++) {
        int L, R;
        cin >> L >> R;
        
        int res = (L + K - 1) % K;

        int boxes = qua[R][res] - qua[L-1][res];
        int good = sum[R][res] - sum[L-1][res];
        int total = pref[R] - pref[L-1];

        cout << (total - good) + (boxes - good) << "\n";
    }
}