#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll N, V, T = 0;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> V;
        T += V;
    }

    cout << N * (N + 1) / 2 - T << "\n";
}