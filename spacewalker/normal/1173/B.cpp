#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = i/2 + 1;
        y[i] = i/2 + (i % 2) + 1;
    }
    printf("%d\n", max(*max_element(begin(x), end(x)), *max_element(begin(y), end(y))));
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}