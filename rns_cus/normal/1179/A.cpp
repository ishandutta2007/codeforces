#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, q, a[N], A[N], B[N], P;

int main() {
    scanf("%d %d", &n, &q); int x = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), x = max(x, a[i]);
    deque <int> dq;
    for (int i = 1; i <= n; i ++) dq.push_back(a[i]);
    while (1) {
        int X = dq.front();
        if (X == x) break;
        dq.pop_front();
        int Y = dq.front(); dq.pop_front(); P ++;
        A[P] = X, B[P] = Y;
        if (X < Y) swap(X, Y);
        dq.push_front(X), dq.push_back(Y);
    }
    for (int i = 1; i <= n; i ++) a[i] = dq.front(), dq.pop_front();
    while (q --) {
        long long m;
        scanf("%lld", &m);
        if (m <= P) printf("%d %d\n", A[m], B[m]);
        else {
            m = (m - P - 1) % (n - 1) + 2;
            printf("%d %d\n", a[1], a[m]);
        }
    }
}