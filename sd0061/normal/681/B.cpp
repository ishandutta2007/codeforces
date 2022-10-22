#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i <= n ; i += 1234567) {
        for (int j = 0 ; i + j <= n ; j += 123456) {
            if ((n - i - j) % 1234 == 0) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}