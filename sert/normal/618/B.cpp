#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;

int n;
int a[100][100];
bool u[100];
int ans[100];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bool fail, fnd;
    for (int z = 1; z <= n; z++) {
        fnd = false;
        for (int j = 0; j < n && !fnd; j++) {
            if (u[j]) continue;
            fail = false;
            for (int i = 0; i < n; i++)
                if (i != j && !u[i] && a[i][j] != z)
                    fail = true;
            if (!fail) {
                ans[j] = z;
                u[j] = true;
                fnd = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}