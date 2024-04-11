#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M, K, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> K;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> T;

        if (T == 1) {
            if (M > 0) M--;
            else ans++;
        } else {
            if (K > 0) K--;
            else if (M > 0) M--;
            else ans++;
        }
    }

    cout << ans << "\n";
}