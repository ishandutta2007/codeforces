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

const int N = (int) 5005, mod = (int) 0;
int n, m, fx[N], fy[N], val[N], is[N];
string num[N], var[N], op[N];
map<string, int> mp;
int get(int b, int best) {
    int bsum = -1, bval = 0;
    for (int bit = 0; bit <= 1; ++bit) {
        val[0] = bit;
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (is[j]) {
                val[j + 1] = num[j][b] - '0';
            } else {
                if (op[j] == "OR") {
                    val[j + 1] = val[fx[j]] | val[fy[j]];
                } else if (op[j] == "XOR") {
                    val[j + 1] = val[fx[j]] ^ val[fy[j]];
                } else if (op[j] == "AND") {
                    val[j + 1] = val[fx[j]] & val[fy[j]];
                } else {
                    assert(0);
                }
            }
            sum += val[j + 1];
        }
        if (bsum == -1 || ((best == 0? sum < bsum: sum > bsum) || (sum == bsum && bval > bit))) {
            bval = bit;
            bsum = sum;
        }
    }
    return bval;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int j = 0; j < n; ++j) {
        cin >> var[j];
        mp[var[j]] = j + 1;
        string eq, x; cin >> eq;
        cin >> x;
        if (x[0] == '0' || x[0] == '1') {
            num[j] = x;
            is[j] = 1;
        } else {
            fx[j] = mp[x];
            string y;
            cin >> op[j];
            cin >> y;
            fy[j] = mp[y];
        }
    }
    for (int j = 0; j < m; ++j)
        cout << get(j, 0);
    cout << endl;
    for (int j = 0; j < m; ++j)
        cout << get(j, 1);
}