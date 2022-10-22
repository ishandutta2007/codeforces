#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 505
int n , K , Q = 1e9 + 7;
void add(int& A , int B) {
    A += B;
    if (A >= Q) {
        A -= Q;
    }
}
int f[2][N][N];
int power[N];
void work() {
    int i , j , k ;
    cin >> n >> K;
    power[0] = 1;
    for (i = 1 ; i <= n ; ++ i)
        power[i] = power[i - 1] << 1 , power[i] %= Q;
    int cur = 0 , nxt = 1;
    f[cur][0][0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (j = 0 ; j <= K ; ++ j) {
            for (k = 0 ; k < i ; ++ k) {
                if (!f[cur][j][k]) continue;
                add(f[nxt][j][k] , (int)((LL)f[cur][j][k] * power[k] % Q));
                if (j < K) {
                    add(f[nxt][j + 1][i] , (int)((LL)f[cur][j][k] * ((power[i] - power[k] + Q) % Q) % Q));
                }
            }
        }
        swap(cur , nxt);
    }
    int ans = 0;
    for (i = 0 ; i <= n ; ++ i)
        add(ans , f[cur][K][i]);
    printf("%d\n" , ans);
}

int main(){
    work();
    return 0;
}