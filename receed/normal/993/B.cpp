#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(2)), b(m, vector<int>(2));
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i][0], &a[i][1]);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &b[i][0], &b[i][1]);
    set<int> s;
    vector<int> sa(n), sb(m);
    int f = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int t1 = 0; t1 < 2; t1++)
                for (int t2 = 0; t2 < 2; t2++) {
                    if (a[i][t1] == b[j][t2] && a[i][1 - t1] != b[j][1 - t2]) {
                        s.insert(a[i][t1]);
                        if (sa[i] && sa[i] != a[i][t1] || sb[j] && sb[j] != a[i][t1])
                            f = -1;
                        sa[i] = a[i][t1];
                        sb[j] = a[i][t1];
                    }
                }
    if (s.size() == 1)
        printf("%d", *s.begin());
    else
        printf("%d", f);
}