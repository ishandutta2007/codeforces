#include <cstdio>
int n, k, l, r, sall, sk, d, q;
void doit(int m, int am) {
    for (int i = 0; i < m; i++) printf("%d ", am / m + (i < am % m ? 1 : 0));
}
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall, &sk);
    doit(k, sk);
    doit(n - k, sall - sk);
}