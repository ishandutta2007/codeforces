#include <cstdio>
using namespace std;
const int N = 1000200;
int n , a[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ a[x];
    }
    for (int i = 0 ; i < N ; ++ i) {
        for (int j = 20 ; j > 0 ; -- j)
            if (a[i] >> j & 1) {
                a[i] -= 1 << j;
                a[i + j] ++;
            }
    }
    int res = 0;
    for (int i = 0 ; i < N ; ++ i)
        res += a[i];
    printf("%d\n" , res);
    return 0;
}