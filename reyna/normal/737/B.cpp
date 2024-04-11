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

const int N = (int) 0, mod = (int) 0;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string cur;
    cin >> cur;
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (cur[i] == '1') {
            cnt = 0;
        } else {
            cnt++;
            if (cnt == b) {
                cur[i] = '1';
                cnt = 0;
                res.push_back(i);
            }
        }
    }
    cout << (int) res.size() - a + 1 << endl;
    for (int i = 0; i < (int) res.size() - a + 1; ++i)
        cout << res[i] + 1 << ' ';
}