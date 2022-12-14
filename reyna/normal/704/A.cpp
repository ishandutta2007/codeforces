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

const int N = (int) 3e5 + 5, mod = 0;
set<int> all;
vector<int> p[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, m = 0;
    cin >> n >> q;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            all.insert(m);
            p[x].push_back(m); ++m;
        } else if (c == 2) {
            int x;
            cin >> x;
            for (int a : p[x])
                all.erase(a);
            p[x].clear();
        } else {
            int tt;
            cin >> tt;
            while ((int) all.size()) {
                int it = *(all.begin());
                if (it < tt)
                    all.erase(it);
                else
                    break;
            }
        }
        cout << (int) all.size() << '\n';
    }

}