#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, R, C;
bool row[64], col[64];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N * N; i++) {
        cin >> R >> C;

        if (!row[R] && !col[C]) {
            cout << i + 1 << " ";
    
            row[R] = true;
            col[C] = true;
        }
    }

    cout << endl;
}