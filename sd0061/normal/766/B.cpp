#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;

int n , a[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    sort(a , a + n);
    if (n >= 200) {
        puts("YES");
    } else {
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = i + 1 ; j < n ; ++ j) {
                for (int k = j + 1 ; k < n ; ++ k) {
                    if (a[i] + a[j] > a[k]) {
                        puts("YES");
                        return 0;
                    }
                }
            }
        }
        puts("NO");
    }
}