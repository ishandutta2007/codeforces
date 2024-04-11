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
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;

int n;
char s[N];
int sum[N];
int S[N] , top;

int check(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return -1;
    return 2;
}

void work() {
    int i ;
    scanf("%s" , s);
    n = strlen(s);
    for (i = 1 ; i <= n ; ++ i)
        sum[i] = sum[i - 1] + check(s[i - 1]);
    S[top ++] = 0;
    int res = 0;
    for (i = 1 ; i <= n ; ++ i) {
        int l = 0 , r = top , m;
        while (l < r) {
            m = l + r >> 1;
            if (sum[S[m]] <= sum[i])
                r = m;
            else
                l = m + 1;
        }
        if (r != top)
            res = max(res , i - S[r]);
        if (sum[i] < sum[S[top - 1]])
            S[top ++] = i;
    }
    if (res) {
        int cnt = 0;
        for (i = res ; i <= n ;  ++ i)
            cnt += (sum[i] - sum[i - res] >= 0);
        printf("%d %d\n" , res , cnt);
    } else
        puts("No solution");
}

int main() {
    work();
    return 0;
}