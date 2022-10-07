#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const string moves[] = {"L", "U", "R", "D", "LU", "RU", "RD", "LD"};
const int mx[] = {-1, 0, 1, 0, -1, 1, 1, -1},
          my[] = {0, 1, 0, -1, 1, 1, -1, -1};
bool match(int a, int b) {
    if (a == 0) {
        return b == 0;
    } else if (a > 0) {
        return b == 1;
    } else {
        return b == -1;
    }
}
int mov(int a, int b) {
    for(int i = 0; i < 8; ++i) {
        if (match(a, mx[i]) && match(b, my[i])) {
            return i;
        }
    }
    return -1;
}
char buf1[10],buf2[10];
int main() {
    scanf("%s %s", buf1, buf2);
    int x = buf2[0] - buf1[0];
    int y = buf2[1] - buf1[1];
    printf("%d\n", max(abs(x), abs(y)));
    while (x || y) {
        int m = mov(x, y);
        x -= mx[m];
        y -= my[m];
        printf("%s\n", moves[m].c_str());
    }
    return 0;
}