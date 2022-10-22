#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 105;
const int Q = 1e9 + 7;
int n , m , a[N][N];
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < m ; ++ j)
            scanf("%d" , &a[i][j]);
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        res = max(res , *min_element(a[i] , a[i] + m));        
    }
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}