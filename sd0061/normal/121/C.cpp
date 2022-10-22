#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL p[20] , a[20];
int n , k , m , d , ans;
bool f[20];
void dfs(LL x) {
    if (x > m) return;
    ++ ans;
    dfs(x * 10 + 4);
    dfs(x * 10 + 7);
}

bool check(int x) {
    char s[12];
    sprintf(s , "%d" , x);
    for (int i = 0 ; s[i] ; ++ i) {
        if (s[i] != '4' && s[i] != '7')
            return 0;
    }
    return 1;
}

void work() {
    scanf("%d%d" , &n , &k);
    p[0] = 1;
    for (int i = 1 ; i <= 15 ; ++ i) {
        p[i] = p[i - 1] * i;
    }
    if (n < 15 && k > p[n]) {
        puts("-1");
        return;
    }
    for (int i = 1 ; i <= 15 ; ++ i) {
        if (p[i] > k) {
            m = n - i;
            d = i;
            break;
        }
    }
    ans = 0;
    dfs(4);
    dfs(7);
    -- k;

    memset(f , 0 , sizeof(f));
    for (int i = 1 , j ; i <= d ; ++ i) {
        int x = k / p[d - i] , y = 0;
        for (j = 1 ; j <= d ; ++ j) {
            if (!f[j])
                ++ y;
            if (y > x) {
                break;
            }
        }
        f[j] = 1 , k %= p[d - i];
        if (check(j + m) && check(i + m)) {
            ++ ans;
        }
    }
    printf("%d\n" , ans);
}

int main() {
    int T = 1;
    while (T --) {
        work();
    }
    return 0;
}