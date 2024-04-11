#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K, L, R;
int SA, SK;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K >> L >> R >> SA >> SK;

    SA -= SK;

    for (int i = 0; i < N - K; i++) {
        int val = SA / (N - K);
        if (i < SA % (N - K)) val++;
        cout << val << " ";
    }

    for (int i = 0; i < K; i++) {
        int val = SK / K;
        if (i < SK % K) val++;
        cout << val << " ";
    }

    cout << "\n";
}