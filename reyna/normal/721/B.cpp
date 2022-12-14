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
const int N = (int) 1e5 + 5, mod = (int) 0;
string a[N];
int n, k;
int f(int x) {
    return (x - 1) / k * 5 + x;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i)
        if (s.size() >= a[i].size()) {
            if (s.size() != a[i].size()) 
                cnt0++;
            cnt1++;
        }
    cnt0++;
    cout << f(cnt0) << ' ' << f(cnt1) << '\n';

}