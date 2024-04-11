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
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector <int> block(m);
    for (int i = 0; i < m; i++) {
        int x1, x2, y1;
        cin >> x1 >> x2 >> y1;
        if (x1 != 1) continue;
        block.push_back(x2);
    }
    sort(block.begin(), block.end());
    int cnt = 0;
    int res = 0;
    while (block.size() && block.back() == (int) 1e9) {
        cnt++;
        block.pop_back();
    }
    res = n + cnt;
    for (int i = n - 1; i >= 0; i--) {
        while (block.size() && block.back() >= a[i]) {
            cnt++;
            block.pop_back();
        }
        res = min(res, cnt + i);
    }
    cout << res;
}