#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;

int n , m , q;
map<string , int> Hash;
int f[N + N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

int main() {
    scanf("%d%d%d" , &n , &m , &q);
    for (int i = 0 ; i < n ; ++ i) {
        f[i] = i , f[i + n] = i + n;
        static char str[50];
        scanf("%s" , str);
        Hash[str] = i;
    }
    for (int i = 0 ; i < m ; ++ i) {
        int o;
        static char a[50] , b[50];
        scanf("%d%s%s" , &o , a , b);
        int x = Hash[a] , y = Hash[b];
        if (o == 1) {
            if (getf(x) == getf(y + n)) {
                puts("NO");
            } else {
                puts("YES");
                f[getf(x)] = getf(y);
                f[getf(x + n)] = getf(y + n);
            }
        } else {
            if (getf(x) == getf(y)) {
                puts("NO");
            } else {
                puts("YES");
                f[getf(x)] = getf(y + n);
                f[getf(x + n)] = getf(y);
            }
        }
    }
    for (int i = 0 ; i < q ; ++ i) {
        static char a[50] , b[50];
        scanf("%s%s" , a , b);
        int x = Hash[a] , y = Hash[b];
        if (getf(x) == getf(y)) {
            puts("1");
        } else if (getf(x) == getf(y + n)) {
            puts("2");
        } else {
            puts("3");
        }
    }
}