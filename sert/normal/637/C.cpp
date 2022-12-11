#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2034;

char s[N][10];
int n, cur, min_dif = 10;

int main() {

    //freopen("a.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    if (n == 1) {
        printf("6");
        return 0;
    }

    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        cur = 0;
        for (int p = 0; p < 6; p++)
            if (s[i][p] != s[j][p])
                cur++;
        min_dif = min(min_dif, cur);
    }

    printf("%d", (min_dif - 1) / 2);

    return 0;
}