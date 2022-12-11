#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 800;
const ll md = 1e9 + 7;

ll c[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    int n;
    cin >> n;
    cout << c[n][5] * c[n][5] * 120;

    return 0;
}