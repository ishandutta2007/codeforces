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
int mark[10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    int szx = 0, szy = 0, tx = x - 1, ty = y - 1;
    while (tx) szx++, tx /= 7;
    while (ty) szy++, ty /= 7;
    szx = max(szx, 1);
    szy = max(szy, 1);
    if (szx + szy > 7) {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j) {
            memset(mark, 0, sizeof mark);
            int a = i, b = j;
            for (int k = 0; k < szx; ++k) mark[a % 7]++, a /= 7;
            for (int k = 0; k < szy; ++k) mark[b % 7]++, b /= 7;
            int flag = 1;
            for (int k = 0; k < 10; ++k)
                if (mark[k] > 1)
                    flag = 0;
            res += flag;
        }

    cout << res << endl;



}