#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int t, n, m, k, cnt, a[N], b[N], avail[1000005], f[1000005];
long long res, sum;
struct Data { int x, y; } c[300005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<=m; ++i) cin >> b[i];
        for(int i=1; i<=k; ++i) cin >> c[i].x >> c[i].y;
        res = 0;

        sort(c+1, c+k+1, [] (Data a, Data b) { return a.x < b.x || a.x == b.x && a.y < b.y; });
        for(int i=1, j=1; i<=n; ++i) {
            ++cnt;
            sum = 0;
            while (j <= k && c[j].x < a[i]) {
                int dy = c[j].y;
                if (avail[dy] != cnt) f[dy] = 0, avail[dy] = cnt;
                res += sum++ - f[dy]++;
                ++j;
            }
            while (j <= k && c[j].x == a[i]) ++j;
        }

        sort(c+1, c+k+1, [] (Data a, Data b) { return a.y < b.y || a.y == b.y && a.x < b.x; });
        for(int i=1, j=1; i<=m; ++i) {
            ++cnt;
            sum = 0;
            while (j <= k && c[j].y < b[i]) {
                int dx = c[j].x;
                if (avail[dx] != cnt) f[dx] = 0, avail[dx] = cnt;
                res += sum++ - f[dx]++;
                ++j;
            }
            while (j <= k && c[j].y == b[i]) ++j;
        }

        cout << res << '\n';
    }
}