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
    int n, m, x;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        a[x - 1]++;
    }
    int ans = m;
    for (int i : a)
        ans = min(ans, i);
    printf("%d", ans);
}