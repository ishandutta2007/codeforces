#include <cstdio>

int main()
{
    int p; scanf("%d", &p);
    int ans = 0;
    for (int x = 1; x < p; x++) {
        bool valid = true;
        int cur = x;
        for (int e = 1; e < p-1; e++) {
            if ((cur % p) == 1) valid = false;
            cur = (cur * x) % p;
        }
        if ((cur % p) != 1) valid = false;
        if (valid) ans++;
    }
    printf("%d\n", ans);
}