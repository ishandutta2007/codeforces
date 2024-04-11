#include <cstdio>

int N, M;
int a[100005];
int d;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < M; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int v, x; scanf("%d%d", &v, &x);
            a[v-1] = x-d;
        }
        else if (t == 2) {
            int y; scanf("%d", &y);
            d += y;
        }
        else /* t == 3 */ {
            int q; scanf("%d", &q);
            printf("%d\n", a[q-1]+d);
        }
    }
}