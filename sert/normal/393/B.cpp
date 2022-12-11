#include <bits/stdc++.h>
using namespace std;
const int N = 190;
typedef long long ll;

void pr(int x) {
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    cout << x / 2 << "." << x % 2 * 5 << " ";
}

int n, w[N][N];

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pr(w[i][j] + w[j][i]);
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pr(w[i][j] - w[j][i]);
        }
        cout << "\n";
    }

    return 0;
}