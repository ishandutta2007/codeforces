#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n , a[N] , b[N];
bool v[N];
int f[N];
long long s[N], res[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
long long ans = 0;
void merge(int x , int y) {
    x = getf(x) , y = getf(y);
    f[y] = x , s[x] += s[y];
    ans = max(s[x] , ans);
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = a[i];
        f[i] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &b[i]);
    }
    for (int i = n ; i > 0 ; -- i) {
        res[i] = ans;
        int x = b[i];
        v[x] = 1;
        ans = max(ans , s[x]);
        if (x > 1 && v[x - 1]) {
            merge(x , x - 1);
        }
        if (x < n && v[x + 1]) {
            merge(x , x + 1);
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        printf("%lld\n" , res[i]);
    }
}