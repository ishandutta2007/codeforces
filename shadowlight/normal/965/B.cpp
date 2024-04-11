#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    vector <vector <char> > a(n, vector <char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int maxk = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') continue;
            int l = j, r = j;
            while (l >= 0 && a[i][l] == '.') l--;
            while (r < n && a[i][r] == '.') r++;
            int u = i, d = i;
            while (u >= 0 && a[u][j] == '.') u--;
            while (d < n && a[d][j] == '.') d++;
            l++, r--, u++, d--;
            int cnt = 0;
            for (int pos = i - k + 1; pos <= i; pos++) {
                if (pos >= u && pos + k - 1 <= d) {
                    cnt++;
                }
            }
            for (int pos = j - k + 1; pos <= j; pos++) {
                if (pos >= l && pos + k - 1 <= r) {
                    cnt++;
                }
            }
            //cout << l << " " << r << " " << u << " " << d << " " << cnt << "\n";
            if (maxk < cnt) {
                maxk = cnt;
                x = i, y = j;
            }
        }
    }
    cout << x + 1 << " " << y + 1 << "\n";
}