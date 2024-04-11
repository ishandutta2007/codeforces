#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n , a[N] , cnt[N] , w[N];

int main() {
    scanf("%d" , &n);
    for (int i = 2 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        ++ cnt[a[i]];
    }

    for (int i = n ; i >= 1 ; -- i) {
        if (cnt[i]) { // not leaf
            if (w[i] < 3) {
                puts("No");
                return 0;
            }
        } else {
            ++ w[a[i]];
        }
    }
    puts("Yes");
}