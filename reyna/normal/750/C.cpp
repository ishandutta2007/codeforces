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
int c[N], d[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int res = 1e9, sum = 0, best = res;
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cin >> c[j] >> d[j];
        sum += c[j];
        d[j]--;
        if (d[j] == 1 && res >= 1900) {
            best -= res - 1899;
            res = 1899;
        }
        res += c[j];
    }
    for (int j = 0; j < n; ++j) {
        if (d[j] != (best < 1900)) {
            cout << "Impossible\n";
            return 0;
        }
        best += c[j];
    }
    if (res >= 2e8) {
        cout << "Infinity\n";
        return 0;
    }
    cout << res << endl;

}