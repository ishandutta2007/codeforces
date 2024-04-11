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
const int N = 1000005;
int n , L[N] , R[N] , cnt[N];

void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        if (!cnt[x])
            L[x] = i;        
        ++ cnt[x];
        R[x] = i;
    }
    int m = *max_element(cnt , cnt + N);
    int res = 1 << 30 , l;
    for (int i = 0 ; i < N ; ++ i) {
        if (cnt[i] == m) {
            if (R[i] - L[i] + 1 < res) {
                res = R[i] - L[i] + 1;
                l = L[i];
            }
        }
    }
    printf("%d %d\n" , l , l + res - 1);
}

int main() {
    work();
    return 0;
}