#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;

int n , a[N] , s[N] , top;
int L[N] , R[N] , ans[N];
int main() {
    int i , x;
    scanf("%d",&n);
    //cerr << n << endl;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d", &a[i]) , a[i] *= -1;
    memset(ans , 0x7F , sizeof(ans));
    top = 0;
    for (i = 1 ; i <= n ; ++ i) {
        while (top && a[s[top]] < a[i])
            R[s[top --]] = i;
        s[++ top] = i;
    }
    while (top)
        R[s[top --]] = i;
    top = 0;
    for (i = n ; i > 0 ; -- i) {
        while (top && a[s[top]] < a[i])
            L[s[top --]] = i;
        s[++ top] = i;
    }
    while (top)
        L[s[top --]] = i;
    for (i = 1 ; i <= n ; ++ i)
        ans[R[i] - L[i] - 1] = min(ans[R[i] - L[i] - 1] , a[i]);
    for (i = n - 1 ; i > 0 ; -- i)
        ans[i] = min(ans[i] , ans[i + 1]);
    for (i = 1 ; i <= n ; ++ i)
        printf("%d\n" , -ans[i]);
    return 0;
}