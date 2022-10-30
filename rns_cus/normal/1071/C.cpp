#include <bits/stdc++.h>
using namespace std;

#define N 100100

typedef pair <int, int> pii;

int n, a[N];
vector <pii> oper;

void solve(int k) {
    while (k && !a[k]) k --;
    if (k <= 2) return;
    if (k <= 12) {
        oper.push_back(pii(k - 2, 1));
        for (int i = 0; i < 3; i ++) a[k-2+i] ^= 1;
        solve(k - 1);
        return;
    }
    if (a[k-2] == 1 && a[k-1] == 1) {
        oper.push_back(pii(k - 2, 1));
        for (int i = 0; i < 3; i ++) a[k-2+i] ^= 1;
        solve(k - 3);
    }
    else if (a[k-2] == 1) {
        oper.push_back(pii(k - 4, 2));
        for (int i = 0; i < 3; i ++) a[k-4+2*i] ^= 1;
        solve(k - 3);
    }
    else if (a[k-1] == 0) {
        oper.push_back(pii(k - 6, 3));
        for (int i = 0; i < 3; i ++) a[k-6+3*i] ^= 1;
        solve(k - 3);
    }
    else {
        if (a[k-5] == 1 && a[k-4] == 1 && a[k-3] == 1) {
            oper.push_back(pii(k - 5, 2));
            oper.push_back(pii(k - 8, 4));
            for (int i = 0; i < 3; i ++) a[k-5+2*i] ^= 1;
            for (int i = 0; i < 3; i ++) a[k-8+4*i] ^= 1;
            solve(k - 6);
        }
        else {
            int x = k - 3, y = k - 3;
            while (x >= k - 5 && !a[x]) x --;
            while (y >= k - 5 && (y == x || !a[y])) y --;
            oper.push_back(pii(2 * x - k, k - x));
            oper.push_back(pii(2 * y - k + 1, k - 1 - y));
            for (int i = 0; i < 3; i ++) a[2*x-k+(k-x)*i] ^= 1;
            for (int i = 0; i < 3; i ++) a[2*y-k+1+(k-1-y)*i] ^= 1;
            solve(k - 6);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    solve(n);
    if (a[2] == 1) {
        if (n < 8) return puts("NO"), 0;
        oper.push_back(pii(5, 1));
        oper.push_back(pii(6, 1));
        oper.push_back(pii(2, 3));
        a[2] = 0;
    }
    if (a[1] == 1) {
        if (n < 7) return puts("NO"), 0;
        oper.push_back(pii(4, 1));
        oper.push_back(pii(5, 1));
        oper.push_back(pii(1, 3));
        a[1] = 0;
    }
    puts("YES");
    int sz = oper.size();
    assert(sz <= (n / 3) + 12);
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) {
        int x = oper[i].first, y = oper[i].second;
        printf("%d %d %d\n", x, x + y, x + 2 * y);
    }
}