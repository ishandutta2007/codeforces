#include <bits/stdc++.h>
using namespace std;
const long long N = 200005, INF = 9e9;
int t, n, m, cnt, rem[N];
long long a[N], FL[N], FR[N];
struct Data{
    long long x, y;
    bool operator < (Data &p) { return x < p.x || x == p.x && y > p.y; }
} b[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i=1; i<=n; ++i) cin >> a[i];
        for(int i=1; i<=m; ++i) cin >> b[i].x >> b[i].y;
        sort(a+1, a+n+1);
        sort(b+1, b+m+1);

        cnt = 0;
        for(int i=1; i<=m; ++i) {
            while (cnt && b[i].y <= b[cnt].y) --cnt;
            b[++cnt] = b[i];
        }
        m = cnt;

        for(int i=1; i<=m; ++i) rem[i] = 0;
        for(int i=1, j=1; i<=n; ++i) {
            while (j <= m && a[i] > b[j].y) ++j;
            while (j <= m && b[j].x <= a[i] && a[i] <= b[j].y) rem[j++] = true;
        }

        cnt = 0;
        for(int i=1; i<=m; ++i) if (!rem[i]) b[++cnt] = b[i];
        m = cnt;

        a[0] = -INF, a[++n] = INF;
        for(int i=1, lft=1; i<=n; ++i) {
            int rgt = lft;
            while (rgt <= m && b[rgt].y < a[i]) ++rgt;
            if (lft == rgt) FL[i] = FR[i] = FR[i-1];
            else {
                long long tmp = min(b[rgt-1].x - a[i-1], a[i] - b[lft].y);
                long long tmp2 = min(b[rgt-1].x - a[i-1], (a[i] - b[lft].y) * 2);
                long long tmp3 = min((b[rgt-1].x - a[i-1]) * 2, a[i] - b[lft].y);
                FL[i] = FR[i-1] + tmp * 2;
                FR[i] = FR[i-1] + min((b[rgt-1].x - a[i-1]) * 2, a[i] - b[lft].y);

                for(int j=lft; j<rgt-1; ++j) {
                    tmp = min(tmp, (b[j].x - a[i-1]) + (a[i] - b[j+1].y));
                    tmp2 = min(tmp2, (b[j].x - a[i-1]) + (a[i] - b[j+1].y) * 2);
                    tmp3 = min(tmp3, (b[j].x - a[i-1]) * 2 + (a[i] - b[j+1].y));
                }
                FR[i] = min(FR[i-1] + tmp3, FL[i-1] + tmp);
                FL[i] = min(FR[i-1] + tmp * 2, FL[i-1] + tmp2);
                lft = rgt;
            }
        }
        cout << FR[n] << '\n';
    }
}