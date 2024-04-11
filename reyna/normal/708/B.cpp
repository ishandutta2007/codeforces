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
const int N = 0, mod = 0;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if (!a00 && !a01 && !a10 && !a11) {
        cout << '0';
        return 0;
    }
    int cnt0 = -1, cnt1 = -1;
    for (int i = 0; (i * (i - 1)) / 2 <= 1e9; ++i) {
        if (i * (i - 1) / 2 == a00) cnt0 = i;
        if (i * (i - 1) / 2 == a11) cnt1 = i;
    }
    if (cnt0 == -1 || cnt1 == -1) {
        cout << "Impossible";
        return 0;
    }
    if (!a01 && !a10 && !a11) {
        string s = "";
        for (int j = 0; j < cnt0; ++j)
            s += '0';
        cout << s;
        return 0;
    }
    if (!a01 && !a10 && !a00) {
        string s = "";
        for (int j = 0; j < cnt1; ++j)
            s += '1';
        cout << s;
        return 0;
    }
    if (cnt0 == -1 || cnt1 == -1 || cnt0 * cnt1 != a01 + a10) {
        cout << "Impossible";
        return 0;
    }
    string s = "";
    for (int j = 0; j < a10 / cnt0; ++j)
        s += '1', cnt1--;
    for (int j = 0; j < cnt0; ++j) {
        s += '0';
        if (cnt1 && cnt0 - j - 1 == a10 % cnt0)
            s += '1', cnt1--;
    }
    for (int j = 0; j < cnt1; ++j)
        s += '1';
    cout << s << endl;





}