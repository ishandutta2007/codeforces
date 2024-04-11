#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1000005;

int n , m , K;
char s[10] , t[10] , p[10];
char str[N][10];


bool dfs(int k , bool large) {
    if (p[m - 1] == '0') return 0;
    if (!~k)
        return large;
    if (s[k] != '?') {
        if (!large && s[k] < t[k])
            return 0;
        p[k] = s[k];
        if (dfs(k - 1 , large || (p[k] > t[k])))
            return 1;
    } else {
        if (large) {
            p[k] = '0';
            if (dfs(k - 1 , large))
                return 1;
            //p[k] = '1';
            //if (dfs(k - 1 ,  large || (p[k] > t[k])))
            //    return 1;
        } else {
            p[k] = t[k];
            if (dfs(k - 1 , large))
                return 1;
            if (t[k] != '9') {
                p[k] = t[k] + 1;
                if (dfs(k - 1 , 1))
                    return 1;
            }
        }
    }
    return 0;
}

void work() {

    int i , j , x;
    scanf("%d",&n);
    x = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , s);
        m = strlen(s);
        K = 0;
        while (x) {
            t[K ++] = '0' + x % 10;
            x /= 10;
        }
        if (!K) {
            t[K ++] = '0';
        }
        t[K] = 0;
        if (m < K)
            break;
        for (j = K ; j < m ; ++ j) t[j] = '0';
        reverse(s , s + m); memset(p , 0 , sizeof(p));
        if (dfs(m - 1 , 0)) {
            p[m] = 0;
            reverse(p , p + m);
            strcpy(str[i] , p);
            x = 0;
            for (j = 0 ; j < m ; ++ j)
                x *= 10 , x += p[j] - '0';
        } else
            break;
    }
    if (i < n)
        puts("NO");
    else {
        puts("YES");
        for (i = 0 ; i < n ; ++ i)
            puts(str[i]);
    }
}

int main() {
    work();
    return 0;
}