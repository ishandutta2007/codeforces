#include <bits/stdc++.h>

int N, T;
bool f[30005];

int main()
{
    scanf("%d%d", &N, &T);
    f[1] = true;
    for (int i = 1; i <= N-1; i++) {
        int a; scanf("%d", &a);
        if (f[i]) f[i+a] = true;
    }
    printf("%s\n", f[T] ? "YES" : "NO");
}