#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M;

    cin >> M >> N;

    vector<bool> on(N, false);

    for (int i = 0; i < M; i++) {
        int S, V;
        cin >> S;

        for (int j = 0; j < S; j++) {
            cin >> V;
            on[V-1] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!on[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}