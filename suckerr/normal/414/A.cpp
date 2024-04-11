#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    if (k == 0) {
        if (n == 1) {
            printf("1\n");
        } else {
            printf("-1");
        }
        return 0;
    }
    
    if (n == 1) {
        printf("-1\n");
        return 0;
    }
    
    if (n / 2 > k) {
        printf("%d\n", -1);
        return 0;
    } else {
        int kk = k - (n / 2 - 1);
        printf("%d %d", kk, kk * 2);
        k -= kk;
        n -= 2;
        int p = 5;
        for(int i = 1; i < n; i += 2) {
            while(p == kk || p == kk * 2 || p + 1 == kk || p + 1 == kk * 2) {
                p++;
            }
            printf(" %d %d", p, p + 1);
            p += 2;
        }
        if (n & 1) {
            while(p == kk || p == kk * 2) {
                p++;
            }
            printf(" %d", p);
        }
        printf("\n");
    }
    return 0;
}