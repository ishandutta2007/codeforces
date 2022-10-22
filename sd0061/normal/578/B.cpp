#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , k , x , a[N] , L[N] , R[N];
void work() {   
    scanf("%d%d%d" , &n , &k, &x);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        L[i] = L[i - 1] | a[i];
    }
    for (int i = n ; i > 0 ; -- i) {
        R[i] = R[i + 1] | a[i];
    }
    LL res = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        LL p = L[i - 1] | R[i + 1];
        LL q = a[i];
        for (int j = 0 ; j < k ; ++ j)
            q *= x;
        res = max(res , p | q);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}