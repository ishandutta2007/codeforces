#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, T;

    cin >> N >> T;

    if (T < 10) {
        cout << T;
        for (int i = 1; i < N; i++) cout << 0;
        cout << "\n";
    } else {
        if (N == 1) cout << -1 << "\n";
        else {
            cout << 1;
            for (int i = 1; i < N; i++) cout << 0;
            cout << "\n";
        }
    }
}