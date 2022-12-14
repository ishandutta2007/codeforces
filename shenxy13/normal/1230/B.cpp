#include <cstdio>
#include <algorithm>
#include <string>
int main() {
    int n, k, ptr = 0;
    scanf("%d %d", &n, &k);
    char num[n];
    for (int i = 0; i < n; ++i) scanf(" %c", &num[i]);
    if (n == 1 && k >= 1) printf("0");
    else if (n == 1) printf("%c", num[0]);
    else {
        while (ptr != n && k != 0) {
            if (ptr == 0) {
                if (num[ptr] != '1') {
                    num[ptr] = '1';
                    --k;
                }
            } else {
                if (num[ptr] != '0') {
                    num[ptr] = '0';
                    --k;
                }
            }
            ++ptr;
        }
        for (int i = 0; i < n; ++i) printf("%c", num[i]);
    }
    return 0;
}