#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    if (x == y && z == 0) printf("0\n");
    else if (x - y - z > 0) printf("+\n");
    else if (x - y + z < 0) printf("-\n");
    else printf("?\n");
    return 0;
}