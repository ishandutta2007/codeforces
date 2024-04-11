#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define MOD 1004535809

int n, q;
vector<pair<int, int> > ops[10005];
bool ans[10005];
int f[10005];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        ops[l].push_back(make_pair(1, x));
        ops[r+1].push_back(make_pair(2, x));
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int id = 0; id < ops[i].size(); id++) {
            pair<int, int> op = ops[i][id];
            if (op.first == 1) {
                for (int x = n; x >= op.second; x--) {
                    f[x] += f[x-op.second];
                    if (f[x] >= MOD) f[x] -= MOD;
                }
            } else {
                for (int x = op.second; x <= n; x++) {
                    f[x] -= f[x-op.second];
                    if (f[x] < 0) f[x] += MOD;
                }
            }
        }
        for (int x = 1; x <= n; x++) if (f[x]) ans[x] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
        if (ans[i]) printf("%d ", i);
    }
    return 0;
}