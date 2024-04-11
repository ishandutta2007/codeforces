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
const int N = 1005;
int n , m;
char s[N][N] , S[N][N];

void work() {
    int i , j , res = 0 , len = 0;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    for (j = 0 ; j < m ; ++ j) {
        for (i = 0 ; i < n ; ++ i)
            S[i][len] = s[i][j];
        len ++;
        for (i = 0 ; i + 1 < n ; ++ i)
            if (strcmp(S[i] , S[i + 1]) > 0)
                break;
        if (i + 1 < n) {
            ++ res , -- len;
            for (i = 0 ; i < n ; ++ i)
                S[i][len] = 0;
        }
    }
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}