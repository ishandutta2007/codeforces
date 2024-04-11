#include <cstdio>
int n;
char ch, c1, c2;
bool fail;
int main() {
    scanf("%d ", &n);
    for (int i = 0; i < n && !fail; i++)
        for (int j = 0; j < n && !fail; j++) {
            scanf("%c ", &ch);
            if (i == 0 && j == 0) c1 = ch;
            if (i == 0 && j == 1) c2 = ch;
            if ((i == j || i + j == n - 1) && ch != c1) fail = true;
            if (i != j && i + j != n - 1 && ch != c2) fail = true;
        }
    if (fail || c1 == c2) printf("NO\n");
    else printf("YES\n");
}