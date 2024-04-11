#include <cstdio>
int n, x, last[100110], per[100110], ans;
bool u[110011];
int main() {
    scanf("%d", &n);
    n++;
    while (n-->1) {
        scanf("%d", &x);
        if (last[x])
            if (per[x] == 0) per[x] = last[x] - n;
            else if (per[x] != last[x] - n) u[x] = true;
        last[x] = n;
    }
    for (int i = 0; i < 100010; i++) if (!u[i] && last[i]) ans++;
    printf("%d\n", ans);
    for (int i = 0; i < 100010; i++) if (!u[i] && last[i]) printf("%d %d\n", i, per[i]);
}