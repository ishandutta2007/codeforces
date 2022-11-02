#include <bits/stdc++.h>

const int max_N = 150000 + 21;

int n, a[max_N], b[max_N];

std::vector<int> vec;

void init(int x) {
    if (~x & 1) {
        vec.push_back(2);
        while (~x & 1) x >>= 1;
    }
    for (int i = 3; 1ll * i * i <= x; i += 2)
        if (!(x % i)) {
            vec.push_back(i);
            while (!(x % i)) x /= i;
        }
    if (x > 1) vec.push_back(x);
}

bool check(int x) {
    for (int i = 2; i <= n; ++i) {
        if ((a[i] % x) && (b[i] % x)) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", a + i, b + i);
    }
    init(a[1]), init(b[1]);
    for (auto x : vec)
        if (check(x)) return printf("%d\n", x), 0;
    return puts("-1"), 0;
}