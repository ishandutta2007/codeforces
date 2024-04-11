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
#define int long long
const int N = (int) 0, mod = (int) 0;

map<int, int> cnt;
void add(int x, int p) {
    vector<int> v;
    while (x) v.push_back(x % 10), x /= 10;
    reverse(v.begin(), v.end());
    int key = 0;
    for (int x : v) key *= 10, key += x & 1;
    cnt[key] += p;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        if (c == '+' || c == '-') {
            int x;
            cin >> x;
            add(x, 1 - (c == '-') * 2);
        } else {
            int p;
            cin >> p;
            cout << cnt[p] << '\n';
        }
    }


}