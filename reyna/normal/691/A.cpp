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
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt += x;
    }
    if (n == 1 && cnt == 1 || n != 1 && n == cnt + 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }





}