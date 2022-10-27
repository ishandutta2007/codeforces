#include <iostream>
using namespace std;
const int N = 200000+10;
int h, sum;
int a[N], par[N];

int main() {
    scanf("%d", &h);

    int fg = 0, pos;

    for (int i = 0; i <= h; i ++) {
        scanf("%d", &a[i]); sum += a[i];
        if (i >= 1 && a[i] >= 2 && a[i-1] >= 2) {
            fg = 1; pos = sum - a[i];
        }
    }

    if (fg == 0) {
        printf("perfect\n");
        return 0;
    }

    printf("ambiguous\n");

    int cur = 0;
    for (int i = 0; i <= h; i ++) {
        for (int j = cur + 1; j <= cur + a[i]; j ++) {
            par[j] = cur;
        }
        cur = cur + a[i];
    }

    for (int i = 1; i <= sum; i ++) {
        printf("%d ", par[i]);
    }
    printf("\n");
    par[pos+1] = pos-1;
    for (int i = 1; i <= sum; i ++) {
        printf("%d ", par[i]);
    }



}