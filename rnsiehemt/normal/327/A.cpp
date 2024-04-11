#include <cstdio>
#include <algorithm>

int main()
{
    int N; scanf("%d", &N);
    int b = -1, s = 0, o = 0;
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        if (a == 0) {
            s++;
        }
        else /* a == 1 */ {
            o++;
            s--;
        }
        b = std::max(b, s);
        s = std::max(s, 0);
    }
    printf("%d\n", o+b);
}