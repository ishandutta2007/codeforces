#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool row[105], col[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, R, C;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> R >> C;
        row[R] = true;
        col[C] = true;
    }

    int rc = 0, cc = 0;

    for (int i = 0; i <= 100; i++) {
        rc += int(row[i]);
        cc += int(col[i]);
    }

    cout << min(rc, cc) << "\n";
}