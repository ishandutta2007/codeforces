#include <bits/stdc++.h>
using namespace std;

int n , a[100] , b[100];
bool f[1000001];

void work() {
    scanf("%d" , &n);
    //n = 100;
    memset(f , 0 , sizeof(f));
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand() % 1000000 + 1;
    }
    sort(a , a + n);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < i ; ++ j) {
            f[a[i] - a[j]] = 1;
        }
    }
    b[0] = 1;
    for (int i = 1 , j = 2 ; i < n ; ++ i) {
        while (1) {
            bool g = 0;
            for (int k = 0 ; k < i ; ++ k) {
                if (f[j - b[k]]) {
                    g = 1;
                    break;
                }
            }
            if (!g) {
                b[i] = j;
                ++ j;
                break;
            }
            ++ j;
        }
    }
    assert(b[n - 1] <= 1000000);
    puts("YES");
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , b[i] , " \n"[i + 1 == n]);
    }
}

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {
        work();
    }
}