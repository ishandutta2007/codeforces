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
const int N = 1e6 + 34;
const ll INF = 2e9 + 34;

int x1 = N, x2 = -1, y1 = N, y2 = -1, n, m, k;
string s[N];

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                k++;
                x1 = min(x1, j);
                x2 = max(x2, j);
                y1 = min(y1, i);
                y2 = max(y2, i);
            }
        }
    }

    if (k == (x2 - x1 + 1) * (y2 - y1 + 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}