#include <iostream>
using namespace std;
int n, a, b;
int main() {
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        ans = max(ans, min(a/i, b/(n-i)) );
    }
    printf("%d\n", ans);
}