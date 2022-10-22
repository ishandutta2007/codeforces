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
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 5005;
int n , a , b , m;
const int Q = 1000000007;
inline void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
int f[2][N];

int main() {
    int i , j , x;
    scanf("%d%d%d%d",&n,&a,&b,&m);
    int cur = 0 , nxt = 1;
    f[cur][a] = 1;
    for (i = 1 ; i <= m ; ++ i) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (j = 1 ; j <= n ; ++ j) {
            if (!f[cur][j]) continue;
            x = abs(j - b);
            add(f[nxt][max(0 , j - x + 1)] , f[cur][j]);
            add(f[nxt][min(n + 1 , j + x)] , Q - f[cur][j]);
        }
        for (j = 1 ; j <= n ; ++ j)
            add(f[nxt][j] , f[nxt][j - 1]);
        for (j = 1 ; j <= n ; ++ j)
            if (f[cur][j])
                add(f[nxt][j] , Q - f[cur][j]);
        swap(nxt , cur);
    }
    int ans = 0;
    for (i = 1 ; i <= n ; ++ i)
        add(ans , f[cur][i]);
    cout << ans << endl;
    return 0;
}