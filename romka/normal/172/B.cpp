#include <cstdio>
#include <map>

std::map<int, int> mm;

int main() {
    int a, b, m, r0;
    scanf("%d %d %d %d", &a, &b, &m, &r0);
    for (int i = 0; ; i++) {
        if (mm.count(r0) > 0) {
            printf("%d\n", i - mm[r0]);
            return 0;
        }
        mm[r0] = i;
        r0 = (a * r0 + b) % m;
    }
}