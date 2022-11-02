#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k = n / 3;
    for (int i = 0; i < k; i ++) printf("%d 0\n", 2 * i);
    for (int i = 0; i < k; i ++) printf("%d 1\n", 2 * i + 1);
    for (int i = 0; i < n - 2 * k; i ++) printf("%d 2\n", 2 * i);

    return 0;
}