#include <iostream>
using namespace std;
const int N = 1000000+10;

int k, n, m;
int a[N], v[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]); v[a[i]] ++;
    }
    int L = 1, R = 0, cnt = 0;
    int res = 0;

    while (R <= 1000000) {
        while (R <= 1000000 && R - L + 1 < m) {
            R += 1; 
            cnt += v[R];
            if (cnt >= k) {
                v[R] -= (cnt - k + 1); 
                res += (cnt - k + 1); 
                cnt -= (cnt - k + 1);
            }
        }
        cnt -= v[L]; L ++;
    }
    printf("%d\n", res);
}