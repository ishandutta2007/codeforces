#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , m , a[N];
vector<int> fac[N];
LL f[N] , res;

LL power(LL A , LL B) {
    LL I = 1;
    while (B) {
        if (B & 1)
            (I *= A) %= Q;
        (A *= A) %= Q , B >>= 1;
    }
    return I;
}

void work() {
    int i , j ;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&a[i]);
        m = max(a[i] , m);
    }
    sort(a , a + n);
    for (i = 1 ; i <= m ; ++ i)
        for (j = i ; j <= m ; j += i)
            fac[j].push_back(i);
    for (i = 1 ; i <= m ; ++ i) {
        f[i] = 1;
        int x = 0 , y;
        for (j = 1 ; j < fac[i].size() ; ++ j) {
            y = lower_bound(a , a + n , fac[i][j]) - a;
            f[i] *= power(j , y - x) , f[i] %= Q;
            x = y;
        }
        f[i] *= (power(j , n - x) - power(j - 1 , n - x) + Q), f[i] %= Q;
        //    printf("%d %lld\n" , i , f[i]);
        res += f[i] , res %= Q;
    }
    /*for (i = 1 ; i <= m ; ++ i) {
        res += f[i] , res %= Q;
        for (j = i + i ; j <= m ; j += i)
            f[j] += Q - f[i] , f[j] %= Q;
            }*/
    cout << res << endl;
    
}

int main() {
    work();
    return 0;
}