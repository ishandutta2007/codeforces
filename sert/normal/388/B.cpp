#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1002;
const int K = 30;

int a[N][N];
bool u[N][N];

void add(int y1, int x1, int y2, int x2) {
    int b = y1 * (K + 1) + x1 + 2;
    int c = y2 * (K + 1) + x2 + 2;
    //cerr << b << " " << c << "\n";
    u[b][c] = u[c][b] = true;
}

int main() {
    //init();

    for (int j = 0; j < K; j++) {
        for (int i = 0; i <= j; i++) {
            add(i, j, i, j + 1);
            add(i, j, i + 1, j + 1);
            add(i, j, j + 1, j);
        }
        for (int i = j + 1; i < K; i++)
            add(i, j, i + 1, j);
    }
    int k;
    cin >> k;
    cout << "1000\n";
    for (int i = 0; i < K; i++)
        if (k & (1 << i))
            add(0, -1, K, i);

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            cout << (u[i][j] ? "Y" : "N");
        }
        cout << "\n";
    }

    return 0;
}