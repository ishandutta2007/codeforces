#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

int n , a[N];
void work() {
    int i , j;
    scanf("%d" , &n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    if (a[n - 1] == 1)
        puts("NO");
    else {
        if (n == 1 || a[n - 2] == 1) {
            puts("YES");
            for (i = 0 ; i < n ; ++ i) {
                if (i)
                    printf("->");
                printf("%d" , a[i]);
            }
        } else {
            for (i = 0 ; i < n - 2 ; ++ i)
                if (!a[i]) 
                    break;
            if (i >= n - 2) {
                puts("NO");
            } else {
                j = i;
                puts("YES");
                for (i = 0 ; i < n ; ++ i) {
                    if (i)
                        printf("->");
                    if (i == j || i == j + 1)
                        printf("(");
                    printf("%d" , a[i]);
                    if (i == n - 2)
                        printf("))");                        
                }
            }
        }
    }
}


int main() {
    work();
    return 0;
}