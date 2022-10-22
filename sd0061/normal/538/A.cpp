#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;

char str[N] , t[N];

void work() {
    scanf("%s" , str);
    int i , j , k ,  n = strlen(str);
    for (i = 0 ; i < n ; ++ i)
        for (j = i ; j < n ; ++ j) {
            int m = 0;
            for (k = 0 ; k < n ; ++ k)
                if (k < i || k > j)
                    t[m ++] = str[k];
            t[m] = 0;
            if (strcmp(t , "CODEFORCES") == 0) {
                puts("YES");
                return;
            }
        }
    puts("NO");
}

int main() {
    work();
    return 0;
}