#include <cstdio>
using namespace std;
const int N = 1000;
int n , a[N] , b[N] , c[N] , v[N];

int main() {
    int T = 1;
    while (T --) {
        scanf("%d" , &n);
        for (int i = 0 ; i < n ; ++ i) {
            scanf("%d%d%d%d" , a + i , b + i , c + i , v + i);
        }
        int res = -1;
        for (int i = 0 ; i < n ; ++ i) {
            bool flag = 0;
            for (int j = 0 ; j < n ; ++ j) {
                if (i != j && a[i] < a[j] && b[i] < b[j] && c[i] < c[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && (res == -1 || v[i] < v[res])) {
                res = i;
            }
        }
        printf("%d\n" , res + 1);
    }
    return 0;
}