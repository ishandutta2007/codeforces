#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e4 + 34;
const long double EPS = 1e-12;
const int INF = 1e9 + 34;

int n, m;
char s[N];
int d;
int a[111][N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d%d ", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s ", s);
        d = INF;
        for (int j = 0; j < m * 2; j++) {
            if (s[j % m] == '1')
                d = 0;
            else
                d++;
            a[i][j] = d;
        }
        if (d >= INF) {
            cout << -1;
            exit(0);
        }
        d = INF;
        for (int j = m * 2 - 1; j >= 0; j--) {
            if (s[j % m] == '1')
                d = 0;
            else
                d++;
            a[i][j] = min(a[i][j], d);
        }
    }
    int ans = INF;
    for (int i = 0; i < m * 2; i++) {
        int d = 0;
        for (int j = 0; j < n; j++)
            d += a[j][i];
        ans = min(ans, d);
    }

    cout << ans;

    return 0;
}