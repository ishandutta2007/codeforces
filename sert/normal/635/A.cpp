#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
int w, h, n, k;
int ans, sum, x, y;
int a[20][20];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> w >> h >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[y - 1][x - 1] = 1;
    }

    for (int x1 = 0; x1 < w; x1++)
        for (int y1 = 0; y1 < h; y1++)
            for (int x2 = x1; x2 < w; x2++)
    for (int y2 = y1; y2 < h; y2++) {
        sum = 0;
        for (int i = y1; i <= y2; i++)
            for (int j = x1; j <= x2; j++)
                sum += a[i][j];
        if (sum >= k)
            ans++;
    }
    cout << ans;



    return 0;
}