#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, A, P;
    cin >> N;

    int T = 0, B = 100;

    for (int i = 0; i < N; i++) {
        cin >> A >> P;
        B = min(B, P);
        T += A * B;
    }

    cout << T << "\n";
}