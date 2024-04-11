// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 2e5 + 5, M = 1024, mod = (int) 0;
int cnt[M], ncnt[M];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for (int j = 0; j < n; ++j) {
        int p;
        cin >> p;
        cnt[p]++;
    }
    for (int d = 0; d < k; ++d) {
        int t = 0;
        for (int j = 0; j < M; ++j) {
            ncnt[j ^ x] += cnt[j] / 2;
            ncnt[j] += cnt[j] / 2;
            if (cnt[j] & 1) {
                if (t % 2 == 0)
                    ncnt[j ^ x]++;
                else
                    ncnt[j]++;
            }
            t += cnt[j];
        }
        memcpy(cnt, ncnt, sizeof cnt);
        memset(ncnt, 0, sizeof ncnt);
    }
    int mn = 1e9, mx = -1e9;
    for (int j = 0; j < M; ++j) {
        if (cnt[j])
            mn = min(mn, j), mx = max(mx, j);
    }
    cout << mx << ' ' << mn << endl;
}