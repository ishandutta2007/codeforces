#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int read() {
    int x = 0, f = 1, c = getchar();
    while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}

map <pii, pii> Mp;

int id[3], a[4], n, ans, cnt;

void add(int c, int a, int b, int id, bool u) {
    pii now = make_pair(a, b);
    if (u && Mp[now].first != 0 && Mp[now].second != id) {
        int tmp = min(Mp[now].first + c, min(a, b));
        if (ans < tmp) {
            ans = tmp;
            ::id[1] = Mp[now].second;
            ::id[cnt = 2] = id;
        }
    }
    if (Mp[now].first < c) Mp[now] = make_pair(c, id);
}

int main(){
    n = read();
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 3; j ++) a[j] = read();
        sort(a,  a + 3);
        if (a[0] > ans) ans = a[0], id[cnt = 1] = i;
        add(a[0], a[1], a[2], i, 1);
        add(a[1], a[0], a[2], i, 0);
        add(a[2], a[0], a[1], i, 0);
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i ++) printf("%d ", id[i]);
    return 0;
}