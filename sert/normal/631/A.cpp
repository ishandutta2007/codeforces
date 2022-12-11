#include <bits/stdc++.h>
using namespace std;
int n, cur, s1, s2;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        s1 |= cur;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        s2 |= cur;
    }
    printf("%d", s1 + s2);
}