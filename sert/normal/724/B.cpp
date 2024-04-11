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

const int N = (int)1e6 + 34;
int n, a[100][100], m;
void swp(int x, int y) {
    for (int i = 0; i < n; i++)
        swap(a[i][x], a[i][y]);
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    bool fail;
    int ko = 0;
    for (int x = 0; x < m; x++)
    for (int y = x; y < m; y++) {
        swp(x, y);
        fail = false;
        for (int i = 0; i < n; i++) {
            ko = 0;
            for (int j = 0; j < m; j++)
                if (a[i][j] != j + 1)
                    ko++;
            if (ko > 2)
                fail = true;
        }
        if (!fail) {
            cout << "YES";
            return 0;
        }
        swp(x, y);
    }
    cout << "NO\n";


    return 0;
}