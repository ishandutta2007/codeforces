#include <bits/stdc++.h>
using namespace std;

int a[101] , n;

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (a[n]) {
        puts("YES");
        printf("1\n1 %d\n" , n);
    } else {
        for (int i = 1 ; i < n ; ++ i) {
            if (a[i]) {
                puts("YES");
                printf("2\n1 %d\n%d %d\n" , i , i + 1 , n);
                return 0;
            }
        }
        puts("NO");
    }
}