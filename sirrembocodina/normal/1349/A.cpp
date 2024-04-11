#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int cnt[200100][20];
int sum_cnt[200100];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    //vector<int> a(n);
    forn (i, n) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j) {
                continue;
            }
            int p = 0;
            while (x % j == 0) {
                x /= j;
                p++;
            }
            cnt[j][p]++;
            sum_cnt[j]++;
        }
        if (x > 1) {
            cnt[x][1]++;
            sum_cnt[x]++;
        }
    }
    int ans = 1;
    forn (i, 200100) {
        if (sum_cnt[i] == 0) {
            continue;
        }
        cnt[i][0] = n - sum_cnt[i];
        int left = 2;
        forn (j, 20) {
            if (cnt[i][j] >= left) {
                forn (k, j) {
                    ans *= i;
                }
                break;
            }
            left -= cnt[i][j];
        }
    }
    cout << ans << endl;
}