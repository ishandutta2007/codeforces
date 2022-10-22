#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , a[N];
void work() {
    int i;
    scanf("%d" , &n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]) , a[i] += i;
    sort(a , a + n);
    for (i = 1 ; i < n ; ++ i)
        if (a[i] == a[i - 1]) {
            puts(":(");
            return;
        }
    for (i = 0 ; i < n ; ++ i)
        printf("%d\n" , a[i] - i);
}

int main() {
    work();
    return 0;
}