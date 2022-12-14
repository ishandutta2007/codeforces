#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long n;
    scanf("%lld", &n);
    for (long long i = 2; i <= 100000; ++i) {
        if (n % i == 0) {
            printf("%lld", (n - i) / 2 + 1);
            return 0;
        }
    }
    printf("1");
    return 0;
}