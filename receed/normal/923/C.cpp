#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 300001, S = N * 63;
int a[N], p[N];
int g[S][2], cnt[S], cc = 0;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        int cv = 0;
        for (int j = 29; j >= 0; j--) {
            int t = (bool) (p[i] & (1 << j));
            if (!g[cv][t])
                g[cv][t] = ++cc;
            cv = g[cv][t];
            cnt[cv]++;
        }
    }
    for (int i = 0; i < n; i++) {
        int cv = 0, ca = 0;
        for (int j = 29; j >= 0; j--) {
            int t = (bool) (a[i] & (1 << j));
            ca *= 2;
            if (cnt[g[cv][t]])
                cv = g[cv][t];
            else {
                cv = g[cv][1 - t];
                ca++;
            }
            cnt[cv]--;
        }
        printf("%d ", ca);
    }

}