#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int ans = -1, n, s, a, b;

int main() {
  //  freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        b = max(b, a);
    }
    cout << b;
    return 0;
}