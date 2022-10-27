#include <iostream>
#include <cmath>
using namespace std;
int t;
int main() {
    scanf("%d", &t);
    while (t --) {
        int n, x, a, b; 
        scanf("%d%d%d%d", &n, &x, &a, &b);
        int ans = min(n - 1, abs(a - b) + x);
        printf("%d\n", ans);
    }
}