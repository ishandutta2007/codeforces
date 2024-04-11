#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --) {
        long long x, y;
        cin >> x >> y;
        x -= y;
        if (x > 1) puts("YES");
        else puts("NO");
    }
}