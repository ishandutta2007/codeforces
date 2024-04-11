#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , a[N] , b[N] , m;
void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a , a + n , greater<int>());
    LL res = 0;
    for (i = 0 ; i < n ; ++ i) {
        if (i + 1 < n && a[i] - a[i + 1] <= 1) {
            b[m ++] = a[i + 1];
            ++ i;
        }
    }
    for (i = 0 ; i < m ; i += 2) {
        if (i + 1 < m)
            res += (LL) b[i] * b[i + 1];
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}