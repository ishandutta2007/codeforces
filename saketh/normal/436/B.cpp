#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2048;

int N, M, K;

int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K;

    char t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> t;

            if (t == '.' || t == 'D') continue;

            if (t == 'U') {
                if ((i&1) == 0) ans[j]++;
            } else if (t == 'R') {
                if (j + i < M) ans[j+i]++;
            } else {
                if (j - i >= 0) ans[j-i]++;
            }
        }
    }

    for (int j = 0; j < M; j++)
        cout << ans[j] << " ";
    cout << "\n";
}