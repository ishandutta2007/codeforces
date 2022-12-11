#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int ans = -1, n, s, a, b;

int main() {
  //  freopen("a.in", "r", stdin);
    cin >> n >> s;
    s *= 100;
    while (n --> 0) {
        cin >> a >> b;
        if (a * 100 + b > s) continue;
        ans = max(ans, (s - a * 100 - b) % 100);
    }
    cout << ans;
    return 0;
}