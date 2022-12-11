#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

const int N = 123;

int n, m, b[N][N], a[N][N], c[N][N];


int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            a[i][j] = 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[i][j] == 0) {
                for (int k = 0; k < n; k++)
                    a[k][j] = 0;
                for (int k = 0; k < m; k++)
                    a[i][k] = 0;
            }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++)
            if (a[k][j] == 1)
                c[i][j] = 1;
        for (int k = 0; k < m; k++)
            if (a[i][k] == 1)
                c[i][j] = 1;
        if (c[i][j] != b[i][j]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}