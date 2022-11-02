#include <bits/stdc++.h>

int n, c[7];
char s[9];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);
        for (int j = 0; j < 7; j++) {
            if (s[j] == '1') {
                c[j]++;
            }
        }
    }
    printf("%d\n", *std::max_element(c, c+7));
}