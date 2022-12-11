#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int n, x, l, r, ans, pr;
int sk[100500];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        ans -= ((l - pr - 1) / x) * x;
        pr = r;
    }
    cout << ans + r;
}