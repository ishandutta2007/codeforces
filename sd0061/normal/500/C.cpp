#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1005;
int n , m;
int w[N];
int q[N] , top , bot;

int main() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&w[i]);
    int res = 0;
    top = 1 , bot = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d",&x);
        for (j = top ; j <= bot ; ++ j)
            if (q[j] == x)
                break;
        if (j <= bot) {
            for ( ; j + 1 <= bot ; ++ j) {
                q[j] = q[j + 1];
                res += w[q[j]];
            }
            q[bot] = x;
        } else {
            for (j = top ; j <= bot ; ++ j)
                res += w[q[j]];
            q[++ bot] = x;
        }
    }
    cout << res << endl;
    return 0;
}