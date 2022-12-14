#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t, x;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &x);
        printf("1 %d\n", x - 1);
    }
    return 0;
}