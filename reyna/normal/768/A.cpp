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

const int N = (int) 1e5 + 5, mod = (int) 0;
int a[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }
    sort(a, a + n);
    if (a[0] == a[n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    int res = n - 2;
    int pt = 0;
    while (a[pt] == a[pt + 1]) pt++, res--;
    pt = n - 1;
    while (a[pt] == a[pt - 1]) pt--, res--;
    cout << res << endl;
}