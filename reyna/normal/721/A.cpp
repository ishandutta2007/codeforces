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
const int N = (int) 0, mod = (int) 0;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> res;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (cnt && (i == n || s[i] == 'W')) {
            res.push_back(cnt);
        }
        if (i == n) continue;
        if (s[i] == 'B') {
            cnt++;
        } else {
            cnt = 0;
        }
    }
    cout << (int) res.size() << '\n';
    for (int x : res)
        cout << x << ' ';

}