#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 105
int n , m , b;
struct fd {
    int c , t , s;
    bool operator < (const fd& R) const {
        return t < R.t;
    }
}a[N];
LL f[2][1 << 20];
void work()
{
    int i , j , k;
    scanf("%d%d%d",&n,&m,&b);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d%d",&a[i].c , &a[i].t , &j);
        while (j --)
            scanf("%d",&k) , a[i].s |= 1 << k - 1;
    }
    LL ans = 1LL << 61;
    sort(a , a + n);
    int cur = 0 , nxt = 1;
        for (i = 0 ; i < 1 << m ; ++ i)
            f[0][i] = 1LL << 61;
    f[0][0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < 1 << m ; ++ j)
            f[nxt][j] = 1LL << 61;
        for (j = 0 ; j < 1 << m ; ++ j) {
            if (f[cur][j] < 1LL << 61) {
                f[nxt][j] = min(f[nxt][j] , f[cur][j]);
                f[nxt][j | a[i].s] = min(f[nxt][j | a[i].s] , f[cur][j] + a[i].c);
            }
        }
        ans = min(ans , f[nxt][(1 << m) - 1] + (LL)a[i].t * b);
        swap(nxt , cur);
    }
    if (ans == 1LL << 61)
        ans = -1;
    cout << ans << endl;
}

int main()
{
   // freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}