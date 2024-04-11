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
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x = 0;
    string s; cin >> s;
    for (int i = 0; i < (int) s.size() - 1; ++i)
        x *= 10, x += s[i] - '0';
    x--;
    char last = s[(int) s.size() - 1];
    int res = 0;
    if (last == 'f') res = 1;
    else if (last == 'e') res = 2;
    else if (last == 'd') res = 3;
    else if (last == 'a') res = 4;
    else if (last == 'b') res = 5;
    else res = 6;
    res += 3 * (x - (x % 4));
    res += (x & 1) * 6;
    res += (x - (x % 4)) + (x & 1);
    cout << res << endl;
}