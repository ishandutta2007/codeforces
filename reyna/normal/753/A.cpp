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
    int sum = 0, n;
    cin >> n;
    for (int j = 1; j <= n + 1; ++j) {
        sum += j;
        if (sum > n) {
            cout << j - 1 << endl;
            for (int x = 1; x <= j; ++x)
                if (sum - x == n) {
                    for (int y = 1; y <= j; ++y)
                        if (x != y)
                            cout << y << ' ';
                    return 0;
                }
        }
    }
}