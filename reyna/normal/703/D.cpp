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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e6 + 6, mod = 0;
int z[N], a[N], ql[N], f[N];
map<int, int> last;
vector<int> pro[N];
int query(int m, int res = 0) { m++;
    while (m > 0)
        res ^= f[m], m -= m & -m;
    return res;
}
void update(int m, int x) { m++;
    while (m < N)
        f[m] ^= x, m += m & -m;
}
int res[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        z[i + 1] = z[i] ^ a[i];
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int r;
        cin >> ql[j] >> r;
        ql[j]--;
        pro[r - 1].push_back(j);
    }
    for (int i = 0; i < n; ++i) {
        if (last.find(a[i]) != last.end())
            update(last[a[i]], a[i]);
        update(i, a[i]);
        for (int j : pro[i])
            res[j] = z[i + 1] ^ z[ql[j]] ^ query(i) ^ query(ql[j] - 1);
        last[a[i]] = i;
    }
    for (int j = 0; j < q; ++j)
        cout << res[j] << '\n';


}