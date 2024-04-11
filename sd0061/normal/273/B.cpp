#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , a[N];
int p[N] , q[N];
void work() {
    int i , x;
    int res = 1 , cnt = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n + n ; ++ i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (i = 0 ; i < n ; ++ i)
        if (a[i] == a[i + n])
            -- cnt;
    p[0] = 1 , q[0] = 0;
    for (i = 1 ; i <= n + n ; ++ i) {
        x = i;
        p[i] = p[i - 1] , q[i] = q[i - 1];
        while (x % 2 == 0)
            x /= 2 , ++ q[i];
        p[i] = (LL) p[i] * x % m;
    }
    n += n;
    sort(a , a + n);
    for (i = 0 ; i < n ; ++ i) {
        int j = 0;
        while (i + j < n && a[i + j] == a[i])
            ++ j;
        i += j - 1;
        res = (LL) res * p[j] % m;
        cnt += q[j];
    }
    while (cnt --)
        res = (res + res) % m;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}