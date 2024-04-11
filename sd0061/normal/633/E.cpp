#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
typedef long long LL;
using namespace std;
const int N = 1000005;
int n , K , v[N] , c[N] , LOG[N];
int fv[20][N] , fc[20][N];

void init(int *a , int n , int f[][N]) {
    for (int i = 0 ; i < n ; ++ i) {
        f[0][i] = a[i];
    }
    for (int j = 1 ; 1 << j <= n ; ++ j) {
        for (int i = 0 ; i + (1 << j) - 1 < n ; ++ i)
            f[j][i] = max(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
    }        
}
int V(int l , int r) {
    int j = LOG[r - l + 1];
    return max(fv[j][l] , fv[j][r - (1 << j) + 1]);
}
int C(int l , int r) {
    int j = LOG[r - l + 1];
    return -max(fc[j][l] , fc[j][r - (1 << j) + 1]);
}
int L(int l , int r) {
    if (l > r || r >= n) return -1 << 30;
    int j = LOG[r - l + 1];
    int V = max(fv[j][l] , fv[j][r - (1 << j) + 1]);
    int C = max(fc[j][l] , fc[j][r - (1 << j) + 1]);
    return min(V , -C);
}
int w[N];

int main() {
    scanf("%d%d" , &n , &K);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &v[i]);
        //v[i] = rand() % 1000 + 1;
        v[i] *= 100;
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &c[i]);
        //c[i] = rand() % 100000 + 1;
        c[i] = -c[i];
    }
    for (int i = 2 ; i <= n ; ++ i)
        LOG[i] = LOG[i >> 1] + 1;
    init(v , n , fv);
    init(c , n , fc);
        
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        j = max(j , i);
        while (j < n && V(i , j) < C(i , j))
            ++ j;
        w[i] = max(L(i , j - 1) , L(i , j));
    }
    sort(w , w + n);
    double res = 0;
    double x = 1;
    for (int i = 0 ; i <= n - K ; ++ i) {
        x /= (n - i);
        res += x * w[i];
        x *= n - K - i;
    }
    printf("%.12f\n" , res * K);
    
    return 0;
}