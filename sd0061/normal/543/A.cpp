#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
int n , m , B , Q;
int a[N] , f[N][N];
void work() {
    int i , j , k;
    cin >> n >> m >> B >> Q;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    f[0][0] = 1;   
    for (i = 0 ; i <= n ; ++ i) {
        if (i) {
            for (j = 0 ; j <= m ; ++ j)
                for (k = 0 ; k <= B ; ++ k) {
                    if (j >= 1 && k >= a[i]) {
                        f[j][k] += f[j - 1][k - a[i]];
                        f[j][k] %= Q;
                    }
                }
        }
        if (i == n) break;
    }
    int res = 0;
    for (i = 0 ; i <= B ; ++ i)
        res += f[m][i] , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}