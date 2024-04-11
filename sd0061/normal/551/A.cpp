#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
typedef long long LL;
int n , a[N];
void work() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n;  ++ i)
        scanf("%d" , &a[i]);
    for (int i = 0 ; i < n ; ++ i) {
        int x = 1;
        for (int j = 0 ; j < n ; ++ j)
            x += a[j] > a[i];
        printf("%d\n" , x);
    }
}

int main() {
    work();
    return 0;
}