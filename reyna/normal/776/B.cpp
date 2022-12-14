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

const int N = (int) 1e5 + 6, mod = (int) 0;
int pr[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n < 3) {
        cout << 1 << endl;
        for (int j = 0; j < n; ++j)
            cout << 1 << ' ';
        cout << endl;
        return 0;
    }
    cout << 2 << endl;
    for (int j = 2; j <= n + 1; ++j) {
        cout << pr[j] + 1 << ' ';
        if (!pr[j]) {
            for (int i = j; i < N; i += j)
                pr[i] = 1;
        }
    }
    
}