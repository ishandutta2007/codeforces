#include <iostream>
using namespace std;
const int N = 200000+10;
int n, k;
int a[N];
int st[N], top = 0, low = 0;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i ++)
        scanf("%d", &a[i]);
    st[0] = n+1;
    for (int i = 1; i <= k; i ++) {
        if (a[i] == low + 1) {
            low ++;
        } else {
            if (top && a[i] > st[top]) {
                return 0 * printf("-1\n");
            }
            st[++top] = a[i];
        }
        while (top && st[top] == low + 1) {
            top --, low ++;
        }
    }

    for (int i = 1; i <= k; i ++) {
        printf("%d ", a[i]);
    }

    while (top >= 0) {
        for (int i = st[top]-1; i > low; i --) {
            printf("%d ", i);
        }
        low = st[top];
        top --;
    }
    printf("\n");
}