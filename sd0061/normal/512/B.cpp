#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 305;

int n , u[N] , v[N];
map<int , int> f[N];
void work() {
    int i ;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&u[i]);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&v[i]);
    int res = 1 << 30;
    f[0][0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        f[i + 1] = f[i];
        for (auto it : f[i]) {
            int x = __gcd(it.first , u[i]);
            int y = it.second + v[i];
            if (!f[i + 1].count(x) || y < f[i + 1][x])
                f[i + 1][x] = y;
        }
        if (f[i + 1].count(1))
            res = min(res , f[i + 1][1]);
    }
    if (res == 1 << 30)
        res = -1;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}