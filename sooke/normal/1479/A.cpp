#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, l, r, a[N];

int query(int i) {
    if (i == 0 || i == n + 1) { return 1e9; }
    if (a[i] > 0) { return a[i]; }
    std::cout << "? " << i << std::endl;
    int res; std::cin >> res; return a[i] = res;
}
int answer(int i) {
    std::cout << "! " << i << std::endl;
    exit(0);
}
int query0(int i) {
    int x = query(i - 1) > query(i);
    int y = query(i + 1) > query(i);
    if (x && y) { answer(i); }
    if (!x && !y) { return 0; }
    return x ? 1 : -1;
}

int main() {
    std::cin >> n;
    l = 1; r = n;
    query0(l); query0(r);
    for (; ; ) {
        int mid = l + r >> 1;
        int k = query0(mid);
        if (k >= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return 0;
}