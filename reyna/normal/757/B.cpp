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

const int N = (int) 2e5 + 5, mod = (int) 0;
int cnt[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                cnt[j]++;
                if (j * j != x)
                    cnt[x / j]++;
            }
        }
    }
    int res = 1;
    for (int j = 2; j < N; ++j)
        res = max(res, cnt[j]);
    cout << res << endl;
}