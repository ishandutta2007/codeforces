#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 1000005;

int n , A,  B;
int a[N] , cur , nxt;
LL f[2][3] , res = 1LL << 60;

void check(int K) {
    //  cout << K << endl;
    if (K == 1) return;
    memset(f[cur] , 0x3f , sizeof(f[cur]));
    cur = 0 , nxt = 1;
    f[cur][0] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        //cout << i << endl;
        memset(f[nxt] , 0x3f , sizeof(f[nxt]));
        for (int j = 0 ; j < 3 ; ++ j) {           
            LL w = f[cur][j];
            if (w == 0x3f3f3f3f3f3f3f3fLL)
                continue;
            //printf("%d %d : %lld\n" , i, j  , w);
            if (j == 0 || j == 1) {
                f[nxt][1] = min(f[nxt][1] , w + A);
            }
            int nj = (j == 1) ? 2 : j , nk;

            if (a[i] % K == 0) {
                f[nxt][nj] = min(f[nxt][nj] , w);
            }
            if ((a[i] + 1) % K == 0) {
                f[nxt][nj] = min(f[nxt][nj] , w + B);
            }
            if ((a[i] - 1) % K == 0) {
                f[nxt][nj] = min(f[nxt][nj] , w + B);
            }       
        }
        swap(cur , nxt);
    }
    for (int i = 0 ; i < 3 ; ++ i)
        res = min(res , f[cur][i]);
}


int main() {
    scanf("%d%d%d" , &n , &A , &B);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int w = -1 ; w <= 1 ; ++ w) {
        int x = a[0] + w;
        for (int i = 2 ; i * i <= x ; ++ i)
            if (x % i == 0) {
                check(i);
                while (x % i == 0)
                    x /= i;
            }
        check(x);
        x = a[n - 1] + w;
        for (int i = 2 ; i * i <= x ; ++ i)
            if (x % i == 0) {
                check(i);
                while (x % i == 0)
                    x /= i;
            }
        check(x);
    }
    cout << res << endl;
    return 0;
}