#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    if (a == n && b == n) return true;
    else return (a + b) < n - 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "Yes" : "No");
}