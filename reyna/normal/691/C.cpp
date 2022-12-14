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

const int N = 0, mod = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t = "";
    cin >> s;
    int flag = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] != '0')
            flag = 1;
        if (flag)
            t += s[i];
    }
    s = t;
    int pos = -1;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '.')
            pos = i;
    }
    if (pos == -1)
        pos = (int) s.size(), s += '.';
    t = "";
    for (int i = 0; i < (int) s.size(); ++i)
        if (s[i] != '.')
            t += s[i];
    string tmp = "";
    flag = 0;
    for (int i = 0; i < (int) t.size(); ++i) {
        if (t[i] != '0')
            flag = 1;
        if (flag) tmp += t[i];
        if (!flag) pos--;
    }
    t = tmp;
    s = "";
    s += t[0]; s += '.';
    for (int i = 1; i < (int) t.size(); ++i)
        s += t[i];
    int sign = pos - 1;
    if (sign != 0) {
        s += 'E';
        string after = "";
        if (sign < 0) s += '-';
        sign = abs(sign);
        while (sign)
            after += (sign % 10) + '0', sign /= 10;
        reverse(after.begin(), after.end());
        s += after;
    }
    flag = 0;
    int l = 0, r = (int) s.size();
    for (int j = 1; j < (int) s.size(); ++j) {
        if (s[j] == 'E') {
            r = j;
            break;
        }
        if (s[j] != '.' && s[j] != '0')
            l = max(l, j);
    }
    t = "";
    for (int i = 0; i < (int) s.size(); ++i)
        if (i <= l || i >= r)
            t += s[i];
    s = t;
    cout << s << '\n';


}