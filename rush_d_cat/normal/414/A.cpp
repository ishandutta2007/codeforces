#include <iostream>
using namespace std;
int n, k;
int main() {
    cin >> n >> k;

    if (n == 1) {
        if (k == 0) {
            printf("1\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }

    if (n / 2 > k) {
        return !printf("-1\n");
    }

    int mx = k-n/2+1;
    int c = 2*mx;
    for (int i = 1; i < n / 2; i ++) {
        printf("%d %d ", c+1, c+2); c += 2;
    }

    printf("%d %d ", mx, 2*mx);
    if (n % 2) printf("900000000\n");
}