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
    int k, a, b;
    cin >> k >> a >> b;
    if (a < k && b < k) {
        cout << -1 << endl;
        return 0;
    }
    if (a < b) swap(a, b);
    if (a >= k && b < k) {
        if (a % k != 0) {
            cout << -1 << endl;
            return 0;
        }
        cout << a / k << endl;
        return 0;
    }
    cout << a / k + b / k << endl;
}