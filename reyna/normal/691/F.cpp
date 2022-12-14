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

const int N = 3e6 + 6, mod = 0;

long long cnt[N], res[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; ++i)
        for (int j = 1; j * i < N; ++j) {
            if (i != j)
                res[j * i] += cnt[i] * 1ll * cnt[j];
            else
                res[j * i] += cnt[i] * 1ll * (cnt[i] - 1);
        }
    for (int i = 1; i < N; ++i)
        res[i] += res[i - 1];
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << n * 1ll * (n - 1) - res[x - 1] << '\n';
    }


}