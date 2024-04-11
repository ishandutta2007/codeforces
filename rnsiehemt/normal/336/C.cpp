#include <cstdio>
#include <algorithm>

int N;
int a[100005];
bool f[32];
int q[100005];
int Q;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 30; i >= 0; i--) {
        std::fill(f, f+30, false);
        for (int j = 0; j < N; j++) {
            if (a[j] & (1 << i)) {
                for (int k = i-1; k >= 0; k--)
                    if (!(a[j] & (1 << k))) f[k] = true;
            }
        }

        bool valid = true;
        for (int k = i-1; k >= 0; k--) if (!f[k]) valid = false;

        if (!valid) continue;
        else {
            for (int j = 0; j < N; j++) {
                if (a[j] & (1 << i)) {
                    q[Q++] = a[j];
                }

            }
            printf("%d\n", Q);
            for (int k = 0; k < Q; k++) printf("%d ", q[k]); printf("\n");
            return 0;
        }
    }
}