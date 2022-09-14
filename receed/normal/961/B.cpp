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
    int n, k, s = 0, ans = 0;
    scanf("%d%d", &n, &k);
    vector<int> a(n), b(n), ps(n + 1);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        ps[i + 1] = ps[i];
        if (b[i])
            s += a[i];
        else
            ps[i + 1] += a[i];
    }
    for (int i = 0; i + k <= n; i++)
        ans = max(ans, ps[i + k] - ps[i]);
    printf("%d", ans + s);
}