#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    int cnt = 1;
    int last = -INF;
    int res = 0;
    int first;
    cin >> last;
    first = last;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x == last + 1) {
            cnt++;
        } else {
            if (cnt == i && first == 1) {
                res = max(res, cnt - 1);
            }
            if (cnt >= 2) {
                res = max(res, cnt - 2);
            }
            cnt = 1;
        }
        last = x;
    }
    if (cnt == n && first == 1) {
        res = max(res, cnt - 1);
    }
    if (last == 1000) {
        res = max(res, cnt - 1);
    } else if (cnt >= 2) {
        res = max(res, cnt - 2);
    }
    cout << res;
}