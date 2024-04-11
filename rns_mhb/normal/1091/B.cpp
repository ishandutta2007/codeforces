#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long X = 0, Y = 0;
    scanf("%d", &n);
    for(int i = 0, x, y; i < 2 * n; i ++) {
        scanf("%d%d", &x, &y);
        X += x, Y += y;
    }
    printf("%d %d\n", int(X / n), int(Y / n));
}