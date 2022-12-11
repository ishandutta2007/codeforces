#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;
int MD = 30;

int k[N];
int c[N][2];
int num = 1;

void add(int x) {
    int q;
    int v = 0;
    k[v]++;
    for (int d = MD; d >= 0; d--) {
        q = !!(x & (1 << d));
        if (c[v][q] == -1) {
            c[v][q] = num;
            num++;
        }
        v = c[v][q];
        k[v]++;
    }
}

void del(int x) {
    int q, v = 0;
    k[v]--;
    for (int d = MD; d >= 0; d--) {
        q = !!(x & (1 << d));
        v = c[v][q];
        k[v]--;
    }
}

int mx_xr(int x) {
    int v = 0, q, res = 0;
    for (int d = MD; d >= 0; d--) {
        q = !(x & (1 << d));
        res = res * 2;
        if (c[v][q] == -1 || k[c[v][q]] == 0)
            q = 1 - q;
        else
            res++;
        v = c[v][q];
    }
    return res;
}

int main() {
    init();
    for (int i = 0; i < N; i++) {
        c[i][0] = c[i][1] = -1;
    }
    add(0);
    int n, x;
    char ch;
    scanf("%d\n", &n);
    while (n--) {
        scanf("%c %d\n", &ch, &x);
        if (ch == '+') add(x);
        if (ch == '-') del(x);
        if (ch == '?') printf("%d\n", mx_xr(x));
    }

    return 0;
}