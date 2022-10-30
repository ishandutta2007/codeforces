#include <cstdio>
#include <cassert>

int N;
int a[100005];
int l, r, x, y;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    a[0] = 0; a[N+1] = 1123456789;
    int state = 0;
    for (int i = 2; i <= N+1; i++) {
        if (state == 0) {
            if (a[i-1] > a[i]) {
                l = a[i-2];
                r = a[i-1];
                x = i-1;
                state = 1;
            }
        }
        else if (state == 1) {
            if (a[i-1] < a[i]) {
                if (!(l < a[i-1] && r < a[i])) {
                    printf("no\n");
                    return 0;
                }
                else {
                    y = i-1;
                    state = 2;
                }
            }
        }
        else if (state == 2) {
            if (a[i-1] > a[i]) {
                printf("no\n");
                return 0;
            }
        }
        else assert(false);
    }
    if (state == 0) {
        x = 1;
        y = 1;
    }
    printf("yes\n");
    printf("%d %d\n", x, y);
}