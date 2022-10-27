#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n, a[N];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    int fg = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) printf("%d\n", a[i] / 2);
        else {
            int x = a[i] / 2;
            if (x * 2 < a[i]) x ++;
            printf("%d\n", x - fg); fg ^= 1;
        }
    }
}