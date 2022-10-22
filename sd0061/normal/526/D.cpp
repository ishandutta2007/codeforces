#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int n , K;
char s[N];
int f[N] , res[N];
void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&K);
    scanf("%s" , s);
    n = strlen(s);
    for (i = 1 ; i < n ; ++ i) {
        j = f[i];
        while (j && s[i] != s[j])
            j = f[j];
        f[i + 1] = (s[i] == s[j]) ? j + 1 : 0;
    }
    for (i = 1 ; i <= n ; ++ i) {
        int l = i - f[i];
        if (f[i] && i % l == 0) {
            j = i / l;
            if (j / K >= j % K)
                res[i] = 1;
        } else {
            j = i / l;
            if (j / K > j % K)
                res[i] = 1;            
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d" , res[i]); puts("");
}

int main() {
    work();
    return 0;
}