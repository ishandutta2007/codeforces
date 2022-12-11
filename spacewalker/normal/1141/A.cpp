#include <cstdio>

using namespace std;

int findSol(int x) {
    if (x == 1) return 0;
    else if (x % 2 == 0) return 1 + findSol(x / 2);
    else if (x % 3 == 0) return 1 + findSol(x / 3);
    else return -1000000000;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    if (m % n != 0) printf("-1\n");
    else {
        int ans = findSol(m/n);
        if (ans < 0) printf("-1\n");
        else printf("%d\n", ans);
    }
}