#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n & 1) {
        bool flag = 0;
        for (int i = 2; i * i <= n && !flag; i ++) {
            if (n % i == 0) {
                flag = 1;
            }
        }
        if (!flag) {
            puts("1");
            return 0;
        }
        n -= 2;
        for (int i = 2; i * i <= n; i ++) {
            if (n % i == 0) {
                puts("3");
                return 0;
            }
        }
        puts("2");
    }
    else {
        if (n == 2) puts("1");
        else puts("2");
    }
}