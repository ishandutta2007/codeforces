#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 20;
int n , a[N][N] , b[N][N];
int g[N][N] , lx[N] , ly[N] , match[N] , slack[N];
int res;
bool fx[N] , fy[N];
int L[N] , R[N];
bool find(int x) {
    fx[x] = 1;
    for (int y = 0 ; y < n ; ++ y) {
        if (fy[y]) continue;
        if (lx[x] + ly[y] == g[x][y]) {
            fy[y] = 1;
            if (!~match[y] || find(match[y])) {
                match[y] = x;
                return 1;
            }
        } else {
            slack[y] = min(slack[y] , lx[x] + ly[y] - g[x][y]);
        }
    }
    return 0;
}
void update() {
    int delta = 1 << 30 , i;
    for (i = 0 ; i < n ; ++ i)
        if (!fy[i])
            delta = min(delta , slack[i]);
    for (i = 0 ; i < n ; ++ i) {
        if (fx[i]) lx[i] -= delta;
        if (fy[i])
            ly[i] += delta;
        else
            slack[i] -= delta;
    }
}
int cal(int mask) {
    int i , j , tmp = 0;
    for (i = 0 ; i < n ; ++ i) {
        match[i] = -1 , lx[i] = ly[i] = 0;
        for (j = 0 ; j < n ; ++ j) {
            if (mask >> i & 1)
                g[i][j] = a[L[i]][R[j]];
            else
                g[i][j] = b[L[i]][R[j]];
            lx[i] = max(lx[i] , g[i][j]);
        }
        tmp += lx[i];
    }
    if (tmp <= res) return 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j)
            slack[j] = 1 << 30;
        while (1) {
            for (j = 0 ; j < n ; ++ j)
                fx[j] = fy[j] = 0;
            if (find(i))
                break;            
            update();
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; ++ i)
        ans += g[match[i]][i];
    return ans;
}
void work() {
    srand(time(0));
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        L[i] = R[i] = i;
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < n ; ++ j)
            scanf("%d" , &a[L[i]][R[j]]);
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < n ; ++ j)
            scanf("%d" , &b[L[i]][R[j]]);
    res = 0;
    vector<int> V;
    for (int i = 0 ; i < 1 << n ; ++ i)
        if (__builtin_popcount(i) == n / 2) {        
            V.push_back(i);
        }
    random_shuffle(V.begin() , V.end());
    for (int i = 0 ; i < V.size() ; ++ i) {
        res = max(res , cal(V[i]));
        if (clock() >= 1.95 * CLOCKS_PER_SEC)
            break;
    }    
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}