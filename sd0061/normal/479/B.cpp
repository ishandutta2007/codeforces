#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 2000005;
int n, m;
int h[N];
vector< pair<int, int> > res;

int main() {
    int x, y, ansh, ansc;
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0 ; i < n ; ++ i) scanf("%d", &h[i]);
        ansc = 0, res.clear();
        while (m--) {
            x = -1;
            for (int i = 0 ; i < n ; ++ i) {
                if (x == -1 || h[i] > h[x]) x = i;
            }
            y = -1;
            for (int i = 0 ; i < n ; ++ i) {
                if (y == -1 || h[i] < h[y]) y = i;
            }
            ansh = h[x] - h[y];
            if (ansh <= 1) break;
            h[x]--, h[y]++, ansc++, res.push_back(make_pair(x + 1, y + 1));
        }
        sort(h, h + n);
        ansh = h[n - 1] - h[0];
        printf("%d %d\n", ansh, ansc);
        for (int i = 0 ; i < res.size() ; ++ i) printf("%d %d\n", res[i].first , res[i].second);
    }
    return 0;
}