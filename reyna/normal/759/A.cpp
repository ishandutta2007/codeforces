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

const int N = (int) 1e6 + 6, mod = (int) 0;
int p[N], mark[N];
void dfs(int v) {
    if (mark[v]) return;
    mark[v] = 1;
    dfs(p[v]);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, add = 1;
    cin >> n;
    for (int j = 0; j < n; ++j)
        cin >> p[j], p[j]--;
    for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        add ^= x;
    }
    int cnt = 0;
    for (int j = 0; j < n; ++j)
        if (!mark[j])
            dfs(j), cnt++;
    cout << add + (cnt == 1? 0: cnt);
}