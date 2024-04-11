#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , x[N] , h[N];
int L[N] , R[N];
void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d" , &x[i] , &h[i]);
    }
    int res = 0;    
    for (int i = 1 ; i <= n ; ++ i) {
        if (i == 1 || i == n)
            ++ res;
        else {
            if (h[i] < x[i] - x[i - 1])
                ++ res;
            else if (h[i] < x[i + 1] - x[i]) {
                ++ res;
                x[i] += h[i];
            }
        }
    }
    printf("%d\n" , res);
}
int main() {
    work();
    return 0;
}