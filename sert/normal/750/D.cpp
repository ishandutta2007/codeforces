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
const int M = 700;

pair <pair<int, int>, int> a[N];
bool u[M][M];
int len;

const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int x, y;
int u1, u2;
int rem, n, t[100], w;

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    a[u2++] = {{340, 340}, 0};

    for (int it = 0; it < n; it++) {
        rem = u2;
        for (int i = u1; i < rem; i++) {
            x = a[i].first.first;
            y = a[i].first.second;
            w = a[i].second;
            for (int j = 0; j < t[it]; j++) {
                u[y][x] = true;
                y += dy[w];
                x += dx[w];
            }
            y -= dy[w];
            x -= dx[w];
            w = (w + 7) % 8;
            a[u2++] = {{x + dx[w], y + dy[w]}, w};
            w = (w + 2) % 8;
            a[u2++] = {{x + dx[w], y + dy[w]}, w};
        }

        u1 = rem;
        sort(a + u1, a + u2);
        u2 = unique(a + u1, a + u2) - a;

        /*for (int i = 335; i <= 345; i++) {
            for (int j = 335; j <= 345; j++)
                cout << (int)u[i][j];
            cout << "\n";
        }
        cout << "\n\n";*/
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            if (u[i][j])
                ans++;

    cout << ans;

    return 0;
}