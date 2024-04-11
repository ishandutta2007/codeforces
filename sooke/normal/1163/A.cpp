#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

const int N = 1005;

int n, m, k, ans;
bool ob[N];

int main() {
    std::cin >> n >> m; k = m;
    for (int i = 1; i <= n; i += 2) {
        if (m) { m--; ob[i] = true; }
    }
    for (int i = 1; i <= n; i++) {
        if (!ob[i] && m) { m--; ob[i] = true; }
    }
    ob[0] = ob[n]; ob[n + 1] = ob[1];
    for (int i = 1; i <= n; i++) {
        if (!ob[i] && ob[i - 1]) { ans++; }
    }
    std::cout << (k ? ans : 1);
    return 0;
}