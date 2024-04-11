#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int Y, X, c;
char a[55][55], b[10];

int main()
{
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) scanf(" %s", a[y]);
    b[4] = '\0';
    for (int y = 0; y < Y-1; y++) for (int x = 0; x < X-1; x++) {
        b[0] = a[y][x]; b[1] = a[y][x+1]; b[2] = a[y+1][x]; b[3] = a[y+1][x+1];
        std::sort(b, b+4);
        if (strcmp(b, "acef") == 0) c++;
    }
    printf("%d\n", c);
}