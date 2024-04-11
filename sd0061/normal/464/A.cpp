#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;

const int N = 1005;
char str[N] , t[N];
int n , p , a[N];

bool dfs(int k , bool large) {

    if (k >= n) {
        return 1;
    }
    char i = large ? str[k] : 'a';
    for ( ; i < 'a' + p ; ++ i) {
        if (k > 0 && i == t[k - 1]) continue;
        if (k > 1 && i == t[k - 2]) continue;
        t[k] = i;
        if (dfs(k + 1 , (large && i == str[k])))
            return 1;
    }
    return 0;
}

void work() {
    int i , j , k;
    scanf("%d%d",&n,&p);
    scanf("%s" , str);
    n = strlen(str);
    for (i = 0 ; i < n ; ++ i)
        a[i] = str[n - i - 1] - 'a';
    ++ a[0];
    i = 0;
    while (i < n && a[i] >= p) {
        a[i] -= p;
        a[i + 1] ++;
        ++ i;
    }
    if (a[n]) {
        puts("NO");
        return;
    }
    for (i = 0 ; i < n ; ++ i)
        str[i] = a[n - i - 1] + 'a';


    if (dfs(0 , 1)) {
        puts(t);
    } else {
        puts("NO");
    }

}

int main() {
    work();
    return 0;
}