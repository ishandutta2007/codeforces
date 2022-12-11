#include <cstdio>
int t, a[100];
char ch;
int main() {
    scanf("%d ", &t);
    for (int i = 0; i < 16; i++) {
        scanf("%c ", &ch);
        if (ch != '.') a[ch - '1']++;
    }
    for (int i = 0; i < 10; i++)
    if (a[i] > 2 * t) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}