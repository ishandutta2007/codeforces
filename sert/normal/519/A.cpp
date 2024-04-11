#include <cstdio>
char ch;
int s;
int main() {
    while (scanf("%c", &ch) != -1) {
        if (ch == 'p') s--;
        if (ch == 'P') s++;
        if (ch == 'n' || ch == 'b') s -= 3;
        if (ch == 'N' || ch == 'B') s += 3;
        if (ch == 'r') s -= 5;
        if (ch == 'R') s += 5;
        if (ch == 'q') s -= 9;
        if (ch == 'Q') s += 9;
    }
    if (s == 0) printf("Draw");
    if (s > 0) printf("White");
    if (s < 0) printf("Black");
    return 0;
}