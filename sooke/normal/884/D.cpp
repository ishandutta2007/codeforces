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

const int maxN = 200005;

typedef long long lol;

int n;
long long ans;
std::priority_queue<lol, std::vector<lol> , std::greater<lol> > q;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { int t; std::cin >> t; q.push(t); }
    if (n % 2 == 0) {
        lol x = q.top(); q.pop();
        lol y = q.top(); q.pop();
        q.push(x + y); ans += x + y;
    }
    while (q.size() >= 3) {
        lol x = q.top(); q.pop();
        lol y = q.top(); q.pop();
        lol z = q.top(); q.pop();
        q.push(x + y + z); ans += x + y + z;
    }
    std::cout << ans << std::endl;
    return 0;
} ///